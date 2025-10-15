/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_background_static.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:25:10 by isibio            #+#    #+#             */
/*   Updated: 2024/04/05 08:25:11 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../include/cub3d_render_background_static.h"

// * this function can replace the get_good_texture_cos() call
// * 	-> replace 'back_cast.' by 'back_cast->'
void	get_good_texture_cos(t_data *data, t_background *back_cast)
{
	if (back_cast->is_floor && data->raycasting.textured_floor)
	{
		back_cast->ty = (int)(data->floor_texture.image_height
				* (back_cast->floor_y - (int)(back_cast->floor_y)))
			& (data->floor_texture.image_height - 1);
		back_cast->tx = (int)(data->floor_texture.image_width
				* (back_cast->floor_x - (int)(back_cast->floor_x)))
			& (data->floor_texture.image_width - 1);
	}
	if (!back_cast->is_floor && data->raycasting.textured_ceiling)
	{
		back_cast->ty = (int)(data->ceiling_texture.image_height
				* (back_cast->floor_y - (int)(back_cast->floor_y)))
			& (data->ceiling_texture.image_height - 1);
		back_cast->tx = (int)(data->ceiling_texture.image_width
				* (back_cast->floor_x - (int)(back_cast->floor_x)))
			& (data->ceiling_texture.image_width - 1);
	}
}

unsigned int	pick_good_bkg_color(t_data *data, t_background back_cast)
{
	unsigned int	color;

	if (back_cast.is_floor)
	{
		if (data->raycasting.textured_floor)
			color = get_image_color(
					data->floor_texture, data->render.mlx_instance,
					back_cast.tx, back_cast.ty);
		else
			color = data->floor_color;
	}
	else
	{
		if (data->raycasting.textured_ceiling)
			color = get_image_color(
					data->ceiling_texture, data->render.mlx_instance,
					back_cast.tx, back_cast.ty);
		else
			color = data->ceiling_color;
	}
	return (color);
}

void	background_cast_init(t_data *data, t_background *back_cast, int y)
{
	calculate_horizon(data, back_cast, y);
	back_cast->ray_dir_x_0 = data->player.dir_x - data->player.plane_x;
	back_cast->ray_dir_y_0 = data->player.dir_y - data->player.plane_y;
	back_cast->ray_dir_x_1 = data->player.dir_x + data->player.plane_x;
	back_cast->ray_dir_y_1 = data->player.dir_y + data->player.plane_y;
	back_cast->row_distance = back_cast->cam_z / back_cast->p;
	back_cast->floor_step_x = back_cast->row_distance * (back_cast->ray_dir_x_1
			- back_cast->ray_dir_x_0) / data->render.image_width;
	back_cast->floor_step_y = back_cast->row_distance * (back_cast->ray_dir_y_1
			- back_cast->ray_dir_y_0) / data->render.image_width;
	back_cast->floor_x = data->player.pos_x
		+ back_cast->row_distance * back_cast->ray_dir_x_0;
	back_cast->floor_y = data->player.pos_y
		+ back_cast->row_distance * back_cast->ray_dir_y_0;
}

void	calculate_horizon(t_data *data, t_background *back_cast, int y)
{
	if (y > (int)data->render.image_height / 2 + (int)data->player.pitch)
	{
		back_cast->is_floor = 1;
		back_cast->cam_z = 0.5 * data->render.image_height
			+ data->player.pos_z;
		back_cast->p = y - data->render.image_height / 2
			- (int)data->player.pitch;
	}
	else
	{
		back_cast->is_floor = 0;
		back_cast->cam_z = 0.5 * data->render.image_height
			- data->player.pos_z;
		back_cast->p = (data->render.image_height / 2 - y
				+ (int)data->player.pitch);
	}
}
