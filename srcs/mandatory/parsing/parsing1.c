/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:55:03 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 19:16:07 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

//1 --- parsing_1
void	begin_map(char **str_file, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (str_file[x])
	{
		while (y <= (int)ft_strlen(str_file[x]) && str_file[x][y] != '\n')
		{
			while (str_file[x][y] == ' ' || str_file[x][y] == '\t')
				y++;
			if (str_file[x][y] == '\n' ||
				ft_isalpha(str_file[x][y]) == 1)
				break ;
			if (ft_isdigit(str_file[x][y]) == 1)
			{
				data->map.first_line = x;
				return ;
			}
			y++;
		}
		x++;
		y = 0;
	}
}

int	under_map_file(char **str_file, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (str_file[x])
		x++;
	x--;
	while (str_file[x] && x > 0)
	{
		while (str_file[x][y] == ' ' || str_file[x][y] == '\t')
			y++;
		if (ft_isdigit(str_file[x][y]) == 0 && str_file[x][y] != '\n')
			return (1);
		else if (ft_isdigit(str_file[x][y]) == 1)
			break ;
		else if (str_file[x][y] == '\n')
		{
			y = 0;
			x--;
		}
	}
	data->map.last_line = x;
	return (0);
}

char	**elem_file(char *path_to_map, int x)
{
	char	**str;
	char	*gnl;
	int		fd;

	fd = open(path_to_map, O_RDONLY, 0777);
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		x++;
		gnl = get_next_line(fd);
	}
	str = malloc(sizeof(char *) * (x + 1));
	close(fd);
	fd = open(path_to_map, O_RDONLY, 0777);
	x = 0;
	while (1)
	{
		str[x] = get_next_line(fd);
		if (!str[x])
			break ;
		x++;
	}
	return (str);
}

char	**first_check(t_data *data, char **str, char *path_to_map, int x)
{
	str = elem_file(path_to_map, 0);
	if (!str[x])
		free_exit(str, NULL, "missing arg in file");
	if (under_map_file(str, data) == 1)
		free_exit(str, NULL, "argument below the map or missing map");
	begin_map(str, data);
	if (parameter_in_file(str, data, 0, 0) == 1)
		free_exit(str, NULL, "missing or unvalid parameter in file");
	return (str);
}

char	**create_map(char *path_to_map, t_data *data)
{
	char	**str_file;
	int		x;
	int		y;
	char	**map;

	map = NULL;
	str_file = NULL;
	x = 0;
	y = 0;
	str_file = first_check(data, str_file, path_to_map, x);
	while (x < data->map.first_line)
	{
		y = skip_space_tab(str_file[x], y);
		if (is_texture(str_file[x], y) == 0)
			path_texture(data, str_file, x, y + 2);
		else if ((str_file[x][y] == 'F' || str_file[x][y] == 'C')
			&& color_path(data, str_file[x]) == 1)
			ft_color(data, str_file, x, y);
		x++;
		y = 0;
	}
	map = ft_map(data, str_file, y);
	free_tab_tab(str_file);
	set_default_player_direction(&data->player, data->map.player_dir);
	return (map);
}
