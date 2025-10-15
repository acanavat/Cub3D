/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycaster_dda.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:47:49 by isibio            #+#    #+#             */
/*   Updated: 2024/04/01 16:47:49 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

// * The ensemble of functions to perform raycasting dda algorithm
static int	handle_dda_foreground(t_data *data, int x, int foreground_hit);
static int	foreground_hit_condition(t_data *data, int foreground_hit, int x);

void	dda_init(t_data *data, int x)
{
	data->raycasting.camera_x = 2 * x / (double)data->render.image_width - 1;
	data->raycasting.ray_dir_x = data->player.dir_x
		+ (data->player.plane_x * data->raycasting.camera_x);
	data->raycasting.ray_dir_y = data->player.dir_y
		+ (data->player.plane_y * data->raycasting.camera_x);
	data->raycasting.map_x = (int)data->player.pos_x;
	data->raycasting.map_y = (int)data->player.pos_y;
	if (!data->raycasting.ray_dir_x)
		data->raycasting.delta_dist_x = 1e30;
	else
		data->raycasting.delta_dist_x = ft_dabs(1 / data->raycasting.ray_dir_x);
	if (!data->raycasting.ray_dir_y)
		data->raycasting.delta_dist_y = 1e30;
	else
		data->raycasting.delta_dist_y = ft_dabs(1 / data->raycasting.ray_dir_y);
}

void	dda_perform(t_data *data, int x)
{
	static int	foreground_hit;

	while (1)
	{
		if (data->raycasting.side_dist_x < data->raycasting.side_dist_y)
		{
			data->raycasting.side_dist_x += data->raycasting.delta_dist_x;
			data->raycasting.map_x += data->raycasting.step_x;
			data->raycasting.side = 0;
		}
		else
		{
			data->raycasting.side_dist_y += data->raycasting.delta_dist_y;
			data->raycasting.map_y += data->raycasting.step_y;
			data->raycasting.side = 1;
		}
		foreground_hit = handle_dda_foreground(data, x, foreground_hit);
		if (!is_foreground_object(data->map.tab_map
				[data->raycasting.map_x][data->raycasting.map_y]))
		{
			foreground_hit = 0;
			break ;
		}
	}
}

// 2d parsing, does not take pitch in count because wall size variable is nedded
// or 3d plane is needed (ray_tracing)
static int	handle_dda_foreground(t_data *data, int x, int foreground_hit)
{
	if (foreground_hit_condition(data, foreground_hit, x))
	{
		foreground_hit = 1;
		data->player.crossair_x = x;
		data->player.pointed_wall_id
			= data->map.tab_map[data->raycasting.map_x][data->raycasting.map_y];
		data->player.pointed_map_x = data->raycasting.map_x;
		data->player.pointed_map_y = data->raycasting.map_y;
		if (data->raycasting.side == 0 && data->raycasting.ray_dir_x < 0)
			data->player.pointed_wall_dir = 'N';
		if (data->raycasting.side == 0 && data->raycasting.ray_dir_x > 0)
			data->player.pointed_wall_dir = 'S';
		if (data->raycasting.side == 1 && data->raycasting.ray_dir_y < 0)
			data->player.pointed_wall_dir = 'W';
		if (data->raycasting.side == 1 && data->raycasting.ray_dir_y > 0)
			data->player.pointed_wall_dir = 'E';
		if (data->raycasting.side == 0)
			data->player.pointed_wall_dist = data->raycasting.side_dist_x
				- data->raycasting.delta_dist_x;
		else
			data->player.pointed_wall_dist = data->raycasting.side_dist_y
				- data->raycasting.delta_dist_y;
	}
	return (foreground_hit);
}

static int	foreground_hit_condition(t_data *data, int foreground_hit, int x)
{
	return (!foreground_hit && x == data->render.image_width / 2
		&& data->map.tab_map [data->raycasting.map_x]
		[data->raycasting.map_y] != MAP_EMPTY);
}
