/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_execution_keys.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:45:45 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 16:45:46 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static void	execute_basic_movement(t_data *data);
static void	execute_special_movement(t_data *data);

void	execute_keys(t_data *data)
{
	if (data->key.exit)
		program_end(data);
	execute_basic_movement(data);
	execute_special_movement(data);
}

static void	execute_basic_movement(t_data *data)
{
	if (data->key.rotate_up)
		if (data->player.pitch <= 700)
			data->player.pitch += 100;
	if (data->key.rotate_down)
		if (data->player.pitch >= -700)
			data->player.pitch -= 100;
	if (data->key.rotate_left)
		rotate_left(data, data->player.rot_speed);
	if (data->key.rotate_right)
		rotate_right(data, data->player.rot_speed);
	if (data->key.move_forward)
		move_forward(data);
	if (data->key.move_backward)
		move_backward(data);
	if (data->key.move_left)
		move_left(data);
	if (data->key.move_right)
		move_right(data);
	if (data->key.respawn)
		respawn(data);
}

static void	execute_special_movement(t_data *data)
{
	if (data->key.sprint)
	{
		if (data->player.move_speed <= DEFAULT_PLAYER_MOVE_SPEED * 2.2)
			data->player.move_speed *= 1.2;
	}
	else if (!data->key.sneak && data->player.gravity_phase == 0)
		data->player.move_speed = DEFAULT_PLAYER_MOVE_SPEED;
	if (data->key.sneak && data->player.gravity_phase == 0)
	{
		if (data->player.pos_z >= data->player.default_pos_z / 2.2)
			data->player.pos_z /= 1.2;
		if (data->player.move_speed >= DEFAULT_PLAYER_MOVE_SPEED / 2.2)
			data->player.move_speed /= 1.2;
	}
	else if (!data->key.sprint && data->player.gravity_phase == 0)
	{
		data->player.move_speed = DEFAULT_PLAYER_MOVE_SPEED;
		data->player.pos_z = data->player.default_pos_z;
	}
	if (data->key.jump)
		if (data->player.gravity_phase == 0)
			data->player.gravity_phase = 1;
}
