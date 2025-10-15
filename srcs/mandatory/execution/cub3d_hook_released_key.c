/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hook_released_key.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:10:17 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 18:10:18 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	log_basic_movement_keys(int keycode, t_data *data);
static void	log_special_keys(int keycode, t_data *data);

int	released_key_hook(int keycode, t_data *data)
{
	if (keycode != 0 && keycode != KEY_DEBUG)
		data->last_released_key = keycode;
	log_basic_movement_keys(keycode, data);
	log_special_keys(keycode, data);
	return (0);
}

static void	log_basic_movement_keys(int keycode, t_data *data)
{
	if (keycode == KEY_ROTATE_UP)
		data->key.rotate_up = 0;
	else if (keycode == KEY_ROTATE_DOWN)
		data->key.rotate_down = 0;
	else if (keycode == KEY_ROTATE_LEFT)
		data->key.rotate_left = 0;
	else if (keycode == KEY_ROTATE_RIGHT)
		data->key.rotate_right = 0;
	else if (keycode == KEY_MOVE_FORWARD)
		data->key.move_forward = 0;
	else if (keycode == KEY_MOVE_BACKWARD)
		data->key.move_backward = 0;
	else if (keycode == KEY_MOVE_LEFT)
		data->key.move_left = 0;
	else if (keycode == KEY_MOVE_RIGHT)
		data->key.move_right = 0;
}

static void	log_special_keys(int keycode, t_data *data)
{
	if (keycode == KEY_RESPAWN)
		data->key.respawn = 0;
	else if (keycode == KEY_EXIT)
		data->key.exit = 0;
	else if (keycode == KEY_SPRINT)
		data->key.sprint = 0;
	else if (keycode == KEY_SNEAK)
		data->key.sneak = 0;
	else if (keycode == KEY_JUMP)
		data->key.jump = 0;
}
