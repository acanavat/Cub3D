/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:32:04 by isibio            #+#    #+#             */
/*   Updated: 2024/03/27 17:18:20 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static void	destroy_images(t_data *data);

void	program_end(t_data *data)
{
	destroy_sprite(data->sprite, data->render.mlx_instance);
	mlx_mouse_show(data->render.mlx_instance, data->render.mlx_window);
	free_tab_tab(data->map.tab_map);
	free(data->raycasting.z_buffer);
	destroy_images(data);
	mlx_destroy_window(data->render.mlx_instance, data->render.mlx_window);
	mlx_destroy_display(data->render.mlx_instance);
	free(data->render.mlx_instance);
	free(data);
	exit(0);
}

static void	destroy_images(t_data *data)
{
	free(data->map.no_path);
	free(data->map.so_path);
	free(data->map.ea_path);
	free(data->map.we_path);
	mlx_destroy_image(data->render.mlx_instance, data->wall_north.img);
	mlx_destroy_image(data->render.mlx_instance, data->wall_south.img);
	mlx_destroy_image(data->render.mlx_instance, data->wall_east.img);
	mlx_destroy_image(data->render.mlx_instance, data->wall_west.img);
	mlx_destroy_image(data->render.mlx_instance, data->door_open.img);
	mlx_destroy_image(data->render.mlx_instance, data->door_closed.img);
	if (data->raycasting.textured_ceiling)
	{
		mlx_destroy_image(data->render.mlx_instance, data->ceiling_texture.img);
		free(data->map.ceiling_path);
	}
	if (data->raycasting.textured_floor)
	{
		mlx_destroy_image(data->render.mlx_instance, data->floor_texture.img);
		free(data->map.floor_path);
	}
	if (data->render.img)
		mlx_destroy_image(data->render.mlx_instance, data->render.img);
}
