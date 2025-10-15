/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_pos_manip.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:50:33 by isibio            #+#    #+#             */
/*   Updated: 2024/04/02 08:50:34 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	move_forward(t_data *data)
{
	if (!is_solid_wall(data->map.tab_map[(int)(data->player.pos_x
				+ (data->player.dir_x * (data->player.move_speed + 0.1)))]
		[(int)(data->player.pos_y)]))
		data->player.pos_x += data->player.dir_x * data->player.move_speed;
	if (!is_solid_wall(data->map.tab_map[(int)(data->player.pos_x)]
		[(int)(data->player.pos_y + (data->player.dir_y
				* (data->player.move_speed + 0.1)))]))
		data->player.pos_y += data->player.dir_y * data->player.move_speed;
}

void	move_backward(t_data *data)
{
	if (!is_solid_wall(data->map.tab_map[(int)(data->player.pos_x
				- (data->player.dir_x * (data->player.move_speed + 0.1)))]
		[(int)(data->player.pos_y)]))
		data->player.pos_x -= data->player.dir_x * data->player.move_speed;
	if (!is_solid_wall(data->map.tab_map[(int)(data->player.pos_x)]
		[(int)(data->player.pos_y - (data->player.dir_y
				* (data->player.move_speed + 0.1)))]))
		data->player.pos_y -= data->player.dir_y * data->player.move_speed;
}

void	move_right(t_data *data)
{
	if (!is_solid_wall(data->map.tab_map[(int)(data->player.pos_x
				+ data->player.dir_y * (data->player.move_speed + 0.1))]
		[(int)(data->player.pos_y)]))
		data->player.pos_x += data->player.dir_y * data->player.move_speed;
	if (!is_solid_wall(data->map.tab_map[(int)(data->player.pos_x)]
		[(int)(data->player.pos_y - data->player.dir_x
			* (data->player.move_speed + 0.1))]))
		data->player.pos_y -= data->player.dir_x * data->player.move_speed;
}

void	move_left(t_data *data)
{
	if (!is_solid_wall(data->map.tab_map[(int)(data->player.pos_x
				- data->player.dir_y * (data->player.move_speed + 0.1))]
		[(int)(data->player.pos_y)]))
		data->player.pos_x -= data->player.dir_y * data->player.move_speed;
	if (!is_solid_wall(data->map.tab_map[(int)(data->player.pos_x)]
		[(int)(data->player.pos_y + data->player.dir_x
			* (data->player.move_speed + 0.1))]))
		data->player.pos_y += data->player.dir_x * data->player.move_speed;
}
