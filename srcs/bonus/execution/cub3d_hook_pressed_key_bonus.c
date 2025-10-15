/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hook_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:21:35 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 18:21:36 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static void	log_basic_movement_keys(int keycode, t_data *data);
static void	log_special_keys(int keycode, t_data *data);

int	pressed_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_EXIT)
		program_end(data);
	single_pressed_key_hook(keycode, data);
	if (keycode != 0 && keycode != KEY_DEBUG)
		data->last_pressed_key = keycode;
	log_basic_movement_keys(keycode, data);
	log_special_keys(keycode, data);
	return (0);
}

static void	log_basic_movement_keys(int keycode, t_data *data)
{
	if (keycode == KEY_ROTATE_UP)
		data->key.rotate_up = 1;
	else if (keycode == KEY_ROTATE_DOWN)
		data->key.rotate_down = 1;
	else if (keycode == KEY_ROTATE_LEFT)
		data->key.rotate_left = 1;
	else if (keycode == KEY_ROTATE_RIGHT)
		data->key.rotate_right = 1;
	else if (keycode == KEY_MOVE_FORWARD)
		data->key.move_forward = 1;
	else if (keycode == KEY_MOVE_BACKWARD)
		data->key.move_backward = 1;
	else if (keycode == KEY_MOVE_LEFT)
		data->key.move_left = 1;
	else if (keycode == KEY_MOVE_RIGHT)
		data->key.move_right = 1;
}

static void	log_special_keys(int keycode, t_data *data)
{
	if (keycode == KEY_RESPAWN)
		data->key.respawn = 1;
	else if (keycode == KEY_EXIT)
		data->key.exit = 1;
	else if (keycode == KEY_SPRINT)
		data->key.sprint = 1;
	else if (keycode == KEY_SNEAK)
		data->key.sneak = 1;
	else if (keycode == KEY_JUMP)
		data->key.jump = 1;
}
