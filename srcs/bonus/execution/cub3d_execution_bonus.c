/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:30:21 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 13:30:22 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static void	lines_render_loop(t_data *data);
static void	calculate_ray_dir(t_data *data);

void	exec(t_data *data)
{
	jump(&data->player, 230, 1.4, 0.06);
	handle_gravity(&data->player, data->player.default_pos_z, 1.1);
	if (data->render.img)
		mlx_destroy_image(data->render.mlx_instance, data->render.img);
	data->render.img = mlx_new_image(data->render.mlx_instance,
			data->render.image_width, data->render.image_height);
	data->render.addr = mlx_get_data_addr(data->render.img,
			&data->render.bits_per_pixel, &data->render.line_length,
			&data->render.endian);
	render_background(data);
	lines_render_loop(data);
	render_sprite(data, data->sprite);
	get_minimap(data->render, data->map.tab_map,
		data->player.pos_x, data->player.pos_y);
	if (data->toggle_render_crossair)
		pixel_put(data->render, data->player.crossair_x,
			data->render.image_height / 2, create_trgb(0, 255, 0, 0));
	print_render(data);
}

static void	lines_render_loop(t_data *data)
{
	int	x;

	x = -1;
	while (++x < (int)data->render.image_width)
	{
		dda_init(data, x);
		calculate_ray_dir(data);
		dda_perform(data, x);
		render_line(data, x);
		data->raycasting.z_buffer[x] = data->raycasting.perp_wall_dist;
	}
}

static void	calculate_ray_dir(t_data *data)
{
	if (data->raycasting.ray_dir_x < 0)
	{
		data->raycasting.step_x = -1;
		data->raycasting.side_dist_x = (data->player.pos_x
				- data->raycasting.map_x) * data->raycasting.delta_dist_x;
	}
	else
	{
		data->raycasting.step_x = 1;
		data->raycasting.side_dist_x = (data->raycasting.map_x + 1.0
				- data->player.pos_x) * data->raycasting.delta_dist_x;
	}
	if (data->raycasting.ray_dir_y < 0)
	{
		data->raycasting.step_y = -1;
		data->raycasting.side_dist_y = (data->player.pos_y
				- data->raycasting.map_y) * data->raycasting.delta_dist_y;
	}
	else
	{
		data->raycasting.step_y = 1;
		data->raycasting.side_dist_y = (data->raycasting.map_y + 1.0
				- data->player.pos_y) * data->raycasting.delta_dist_y;
	}
}
