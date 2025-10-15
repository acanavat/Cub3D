/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanavat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:52:38 by acanavat          #+#    #+#             */
/*   Updated: 2024/04/04 19:53:33 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	parse_map_3(char **str, char **map, int x, int y)
{
	while (map[x + 1])
	{
		while (map[x][y])
		{
			if (map[x][y] == '0' && (map[x][y + 1] == 'x' \
					|| map[x][y - 1] == 'x' || \
					map[x + 1][y] == 'x' || map[x - 1][y] == 'x'))
				free_exit(str, map, "open map");
			y++;
		}
		y = 0;
		x++;
	}
}

char	**creation_map(t_data *data, char **str, int x, int y)
{
	char	**map;
	int		z;

	z = 0;
	map = ft_calloc(line_too_long(data) + 2, sizeof(char *));
	while (x <= data->map.last_line)
	{
		map[z] = ft_calloc(data->map.line_size + 2, sizeof(char));
		while (str[x][y])
		{
			if (str[x][y] == ' ')
				map[z][y] = '1';
			else if (ft_isalpha(str[x][y]) == 1 || str[x][y] == 'M')
				map[z][y] = '0';
			else if (str[x][y] != '\n')
				map[z][y] = str[x][y];
			y++;
		}
		map = empty_case(data, map, z, y);
		z++;
		y = 0;
		x++;
	}
	map[z] = NULL;
	return (map);
}

void	line_size(char **str, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = data->map.first_line;
	while (x <= data->map.last_line)
	{
		while (str[x][y] && str[x][y] != '\n')
			y++;
		if (data->map.line_size < y)
			data->map.line_size = y;
		y = 0;
		x++;
	}
}

void	pos_player(t_data *data, char **str, int x, int y)
{
	int	player;

	player = 0;
	while (x < data->map.last_line)
	{
		while (str[x][y])
		{
			if (str[x][y] == 'N' || str[x][y] == 'S' || \
					str[x][y] == 'E' || str[x][y] == 'W')
			{
				data->map.player_dir = str[x][y];
				player++;
				set_default_player_position(&data->player,
					x - data->map.first_line + 0.5, y + 0.5, 100);
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (player != 1)
		free_exit(str, NULL, "invalid player");
}
