/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:49:38 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 12:49:39 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	print_render(t_data *data)
{
	mlx_put_image_to_window(data->render.mlx_instance,
		data->render.mlx_window, data->render.img, 0, 0);
	if (data->toggle_debug_menu == 1)
	{
		if (data->toggle_key_debug_menu == 1)
			print_debug_key_menu(data);
		else
			print_debug_menu(data);
	}
}

void	set_background_renderer(
	t_raycasting *raycasting, int ceiling, int floor)
{
	raycasting->textured_ceiling = ceiling;
	raycasting->textured_floor = floor;
}
