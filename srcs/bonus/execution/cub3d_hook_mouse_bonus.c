/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hook_mouse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:31:30 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 16:31:31 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

// non constant with small / big window
int	mouse_hook(void *mlx_instance, void *mlx_window, t_data *data)
{
	int		x;
	int		y;
	int		new_pitch;

	mlx_mouse_get_pos(mlx_instance, mlx_window, &x, &y);
	new_pitch = 0;
	new_pitch = (int)(data->player.pitch)
		+ (int)((data->render.image_height / 2) - y) / 2;
	if (new_pitch >= -700 && new_pitch <= 700)
		data->player.pitch = new_pitch;
	if (x < (int)(data->render.image_width / 2))
		rotate_left(data, ((data->render.image_width / 2 - x)
				* data->player.mouse_speed));
	if (x > (int)(data->render.image_width / 2))
		rotate_right(data, (double)(x - data->render.image_width / 2)
			* data->player.mouse_speed);
	mlx_mouse_move(mlx_instance, mlx_window,
		data->render.image_width / 2, data->render.image_height / 2);
	return (0);
}
