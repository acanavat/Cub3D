/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanavat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:18:49 by acanavat          #+#    #+#             */
/*   Updated: 2024/04/04 19:22:08 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	stock_texture(char *str, char *path, t_data *data)
{
	int	x;

	x = 0;
	while (ft_isalpha(str[x]) != 1)
		x++;
	if (str[x] == 'N')
		data->map.no_path = ft_strdup(path);
	if (str[x] == 'S')
		data->map.so_path = ft_strdup(path);
	if (str[x] == 'E')
		data->map.ea_path = ft_strdup(path);
	if (str[x] == 'W')
		data->map.we_path = ft_strdup(path);
}

void	open_texture(char **str, char *path, int fd)
{
	int	x;

	x = 0;
	fd = open(path, O_DIRECTORY, 0777);
	if (fd != -1)
		exit_for_texture(str, path, fd);
	fd = open(path, O_RDONLY, 0777);
	if (fd == -1)
		exit_for_texture(str, path, fd);
	while (path[x] && path[x] != '\n')
		x++;
	if (path[x - 1] == 'm' && path[x - 2] == 'p' \
		&& path[x - 3] == 'x' && path[x - 4] == '.')
		return ;
	exit_for_texture(str, path, fd);
}

void	path_texture(t_data *data, char **str, int x, int y)
{
	int		fd;
	char	*path;
	int		path_length;

	path_length = 0;
	fd = y;
	y = skip_space_tab(str[x], y);
	if (fd == y)
		free_exit(str, NULL, "invalid path");
	while (ft_isprint(str[x][y]) == 1 && str[x][y] != ' ' && str[x][y] != '\t')
	{
		y++;
		path_length++;
	}
	if (path_length == 0)
		free_exit(str, NULL, "missing path");
	path = ft_substr(str[x], y - path_length, path_length);
	open_texture(str, path, fd);
	stock_texture(str[x], path, data);
	close(fd);
	free(path);
}

int	is_texture(char *str, int y)
{
	if (str[y] == 'N' && str[y + 1] == 'O')
		return (0);
	if (str[y] == 'S' && str[y + 1] == 'O')
		return (0);
	if (str[y] == 'W' && str[y + 1] == 'E')
		return (0);
	if (str[y] == 'E' && str[y + 1] == 'A')
		return (0);
	return (1);
}
