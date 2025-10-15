/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanavat <acanavat@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:24:54 by acanavat          #+#    #+#             */
/*   Updated: 2024/04/11 18:38:11 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	skip(char *str, int x)
{
	x++;
	while (str[x] == ' ' || str[x] == '\t')
		x++;
	while (str[x] && ft_isprint(str[x]) == 1 && str[x] != ' '
		&& str[x] != '\t')
		x++;
	x--;
	return (x);
}

void	copy(t_data *data, char *str, char c, int x)
{
	int	z;
	int	h;

	h = 0;
	z = x - 1;
	while (x > 0 && str[x] != ' ' && str[x] != '\t')
		x--;
	x++;
	while (str[h] == ' ' || str[h] == '\t')
		h++;
	z -= h;
	if (c == 'c')
		data->map.ceiling_path = ft_substr(str, x, z);
	else
		data->map.floor_path = ft_substr(str, x, z);
}

char	**empty_case(t_data *data, char **map, int z, int y)
{
	y--;
	while (y <= data->map.line_size)
	{
		if (map[z][y] != '1' && map[z][y] != '0')
			map[z][y] = 'x';
		y++;
	}
	map[z][y] = '\0';
	return (map);
}

int	line_too_long(t_data *data)
{
	int	x;

	x = data->map.last_line - data->map.first_line;
	return (x);
}

int	check(char map)
{
	if (map == '0' || map == '-' || map == '+' || map == 'M')
		return (0);
	return (1);
}
