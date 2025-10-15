/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hook_single_pressed.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:21:42 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 16:21:44 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static void	cub3d_pause(t_data *data);

int	single_pressed_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_PAUSE)
		cub3d_pause(data);
	else if (keycode == KEY_INTERACT)
		interact(&data->player, data->map.tab_map);
	else if (keycode == KEY_DEBUG)
		toggle(&data->toggle_debug_menu);
	else if (keycode == KEY_KEY_DEBUG)
		toggle(&data->toggle_key_debug_menu);
	else if (keycode == KEY_CROSSAIR)
		toggle(&data->toggle_render_crossair);
	else if (keycode == KEY_RENDER_WALLS)
		toggle(&data->toggle_render_walls);
	else if (keycode == KEY_RENDER_BACKGROUND)
		toggle(&data->toggle_render_background);
	else if (keycode == KEY_RENDER_SPRITES)
		toggle(&data->toggle_render_sprites);
	if (data->render.img)
		print_render(data);
	return (0);
}

static void	cub3d_pause(t_data *data)
{
	if (data->toggle_pause)
	{
		mlx_mouse_hide(data->render.mlx_instance, data->render.mlx_window);
		mlx_mouse_move(data->render.mlx_instance, data->render.mlx_window,
			data->render.image_width / 2, data->render.image_height / 2);
		data->toggle_pause = 0;
	}
	else
	{
		mlx_mouse_show(data->render.mlx_instance, data->render.mlx_window);
		data->toggle_pause = 1;
	}
}
