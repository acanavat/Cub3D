/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanavat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:28:25 by acanavat          #+#    #+#             */
/*   Updated: 2024/04/04 19:29:56 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	exit_floor_ceilling(char *str_file, int y)
{
	int	count;

	count = 0;
	if (str_file[y + 1] != ' ' && str_file[y + 1] != '\t')
		return (1);
	y = 0;
	while (str_file[y])
	{
		if (str_file[y] == ',')
			count++;
		y++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int	parse_color(char *str, int x)
{
	int	count;

	while (x <= (int)ft_strlen(str) && ft_isdigit(str[x]) != 1 && str[x] != ',')
		x++;
	if (x >= (int)ft_strlen(str))
		return (0);
	while (str[x])
	{
		count = 0;
		while (str[x] == ' ' || str[x] == '\t')
			x++;
		while (ft_isdigit(str[x]) == 1)
		{
			count++;
			x++;
		}
		while (str[x] == ' ' || str[x] == '\t')
			x++;
		if ((str[x] != ',' && str[x] != '\n') || count == 0)
			return (1);
		else
			x++;
	}
	return (0);
}

void	ft_color(t_data *data, char **str, int x, int y)
{
	char		**rgb;
	long long	stop;

	stop = 2147483647;
	rgb = NULL;
	if (parse_color(str[x], 0) == 1)
		free_exit(str, rgb, "invalid argument for rgb");
	if (exit_floor_ceilling(str[x], y) == 1 || \
			parse_floor_ceilling(str[x], y, 1) == 1)
		free_exit(str, rgb, "invalid argument for rgb");
	if (str[x][y] == 'F' || str[x][y] == 'C')
	{
		rgb = ft_split(&str[x][y + 1], ',');
		if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 \
				|| ft_atoi(rgb[2]) > 255)
			free_exit(str, rgb, "invalid range color");
		stock_trgb(data, str[x][y], rgb);
	}
	if (stop < ft_atol(rgb[0]) || stop < ft_atol(rgb[1]) \
			|| stop < ft_atol(rgb[2]))
		free_exit(str, rgb, "invalid range color");
	free_tab_tab(rgb);
}

int	color_path(t_data *data, char *str)
{
	int	x;
	int	im_c;

	im_c = 0;
	x = 0;
	while (str[x] != 'C' && str[x] != 'F')
		x++;
	if (str[x] == 'C')
		im_c = 1;
	x = skip(str, x);
	if (x > 3 && str[x] == 'm' && str[x - 1] == 'p'
		&& str[x - 2] == 'x' && str[x - 3] == '.')
	{
		if (im_c == 1)
			copy(data, str, 'c', x);
		else
			copy(data, str, 'f', x);
	}
	else
		return (1);
	return (0);
}
