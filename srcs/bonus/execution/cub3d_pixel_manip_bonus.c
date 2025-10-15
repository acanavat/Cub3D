/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_pixel_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:26:36 by isibio            #+#    #+#             */
/*   Updated: 2024/04/01 17:26:37 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

int	pixel_get(t_image image, int x, int y)
{
	char	*color;

	color = image.addr
		+ (y * image.line_length + x * (image.bits_per_pixel / 8));
	return (*(unsigned int *)color);
}

void	pixel_put(t_image image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= (int)image.image_width
		|| y < 0 || y >= (int)image.image_height)
		return ;
	dst = image.addr + (y * image.line_length + x * (image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_image image, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 4;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pixel_put(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// old draw_ver_line() function,
// still working but function prototype coded with the cul (t_data *data)
//  	-> remove 'data->window_width,data->window_height', no more implemented
/*
	void	draw_ver_line
	(t_data *data, unsigned int x, unsigned int y, unsigned int y2, int color)
	{
		unsigned int i;

		i = y - 1;
		while (++i != y2 && x < data->window_width && i < data->window_height)
			pixel_put(data->render, x, i, color);
	}
*/