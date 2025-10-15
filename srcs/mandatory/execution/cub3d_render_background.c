/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_background.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:16:44 by isibio            #+#    #+#             */
/*   Updated: 2024/04/03 16:16:45 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../include/cub3d_render_background_static.h"

void	render_background(t_data *data)
{
	t_background	back_cast;
	int				y;
	int				x;

	y = -1;
	while (++y < (int)data->render.image_height)
	{
		background_cast_init(data, &back_cast, y);
		x = -1;
		while (++x < (int)data->render.image_width)
		{
			get_good_texture_cos(data, &back_cast);
			back_cast.floor_x += back_cast.floor_step_x;
			back_cast.floor_y += back_cast.floor_step_y;
			if (data->toggle_render_background)
				pixel_put(
					data->render, x, y, pick_good_bkg_color(data, back_cast));
		}
	}
}
