/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:58:10 by isibio            #+#    #+#             */
/*   Updated: 2024/04/02 13:58:11 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"
#include "../../../include/cub3d_render_line_static_bonus.h"

void	render_line(t_data *data, int x)
{
	t_line	line_cast;

	if (data->raycasting.side == 0)
		data->raycasting.perp_wall_dist = (data->raycasting.side_dist_x
				- data->raycasting.delta_dist_x);
	else
		data->raycasting.perp_wall_dist = (data->raycasting.side_dist_y
				- data->raycasting.delta_dist_y);
	data->raycasting.line_length = (int)(data->render.image_height
			/ data->raycasting.perp_wall_dist);
	data->raycasting.draw_start = -data->raycasting.line_length / 2
		+ data->render.image_height / 2 + (int)data->player.pitch
		+ (int)(data->player.pos_z / data->raycasting.perp_wall_dist);
	if (data->raycasting.draw_start < 0)
		data->raycasting.draw_start = 0;
	data->raycasting.line_end = data->raycasting.line_length / 2
		+ data->render.image_height / 2 + (int)data->player.pitch
		+ (int)(data->player.pos_z / data->raycasting.perp_wall_dist);
	if (data->raycasting.line_end >= (int)data->render.image_height)
		data->raycasting.line_end = data->render.image_height - 1;
	line_cast.wall_x = get_wall_x(data);
	get_good_image_resolution(data, &line_cast);
	line_cast.tex_x = get_tex_x(data->raycasting, &line_cast);
	draw_line(&data->render, data, line_cast, x);
}
