/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanavat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:47:42 by acanavat          #+#    #+#             */
/*   Updated: 2024/04/10 19:38:05 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	last_wall(char *map)
{
	int	x;

	x = 0;
	while (map[x] && map[x] != '\n')
		x++;
	x--;
	while (map[x] == ' ')
		x--;
	if (map[x] == '1' || (map[x] == '0' && map[x + 1] == ' ') || \
			(map[x] == '+' && map[x + 1] == ' ') || \
			(map[x] == '-' && map[x + 1] == ' ') || \
			(map[x] == 'M' && map[x + 1] == ' '))
		return (0);
	return (1);
}

// bordure map
void	parse_map_2(t_data *data, char **str, int x, int y)
{
	while (x < data->map.last_line)
	{
		while (str[x][y])
		{
			while (str[x][y] == ' ')
				y++;
			if (str[x][y] != '1' || last_wall(str[x]) == 1)
				free_exit(str, NULL, "open map");
			else
				break ;
		}
		y = 0;
		x++;
	}
}

int	extremity(char *map)
{
	int	x;

	x = 0;
	while (map[x] == '1' || map[x] == ' ')
		x++;
	if (map[x] != '\0' && map[x] != '\n')
		return (1);
	return (0);
}

void	parse_map_1(t_data *data, char **str, int x, int y)
{
	if (extremity(str[data->map.first_line]) == 1 || \
			extremity(str[data->map.last_line]) == 1)
		free_exit(str, NULL, "open map");
	while (x <= data->map.last_line)
	{
		while (str[x][y])
		{
			if (str[x][y] != ' ' && str[x][y] != '0'
				&& str[x][y] != '1' && str[x][y] != '\n'
				&& str[x][y] != 'N' && str[x][y] != 'S'
				&& str[x][y] != 'E' && str[x][y] != 'W'
				&& str[x][y] != '-' && str[x][y] != '+'
				&& str[x][y] != 'M')
				free_exit(str, NULL, "invalid map");
			y++;
		}
		y = 0;
		x++;
	}
}

char	**ft_map(t_data *data, char **str, int y)
{
	int		x;
	char	**map;

	map = NULL;
	x = data->map.first_line;
	parse_map_1(data, str, x, y);
	parse_map_2(data, str, x, y);
	x = data->map.first_line + 1;
	pos_player(data, str, x, y);
	x = data->map.first_line;
	line_size(str, data);
	map = creation_map(data, str, x, y);
	x = 0;
	parse_map_3(str, map, x, y);
	return (map);
}
