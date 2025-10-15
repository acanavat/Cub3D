/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:10:49 by isibio            #+#    #+#             */
/*   Updated: 2024/03/22 17:53:05 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

/*
	todo :
		- improve collisions
		- ? texture resolution from .xpm file
		- ? opti background
		- print map / texture path in F3
*/

// * This is a downgraded version of the cub3d_bonus part,
// * here all the changes :
// * 	Sprite managment
// * 	 -> removed toggle_render_sprites variable
// * 	 -> removed all the references and code of the render_sprite() func
// * 	 -> removed all functions relative to sprites
// * 	 -> removed struct s_sprite (and type) and references in the code
// * 	 -> removed KEY_RENDER_SPRITES define from cub3d.h
// *
// * 	Mouse control
// * 	 -> removed mlx_mouse* calls
// * 	 -> removed mouse_hook() func, calls and references
// * 	 -> removed DEFAULT_PLAYER_MOUSE_SPEED define from cub3d.h
// * 	 -> removed *mouse* variables in s_player struct
// *
// * 	Minimap
// * 	 -> removed get_minimap() func, calls and references
// *
// * 	Doors
// * 	 -> removed interact() / interact_with_doors() functions, calls and refs
// * 	 -> remove KEY_INTERACT MAP_DOOR_OPEN MAP_DOOR_CLOSED from cub3d.h
// * 	 -> remove texture door_* variables in data struct
// * 	 -> edited is_foreground_object() functions
// * 	 -> edited is_invalid_printable_map_char() functions
// * 	 -> edited is_solid_wall() functions

static void	init_textures(void *mlx_instance, t_data *data);

int	main(int argc, char **argv)
{
	t_data	*data;

	parse(argc, argv);
	data = data_init(argv);
	data->render.mlx_instance = mlx_init();
	init_textures(data->render.mlx_instance, data);
	data->raycasting.z_buffer = malloc(sizeof(
				double) * data->render.image_width);
	data->render.mlx_window = mlx_new_window(
			data->render.mlx_instance, data->render.image_width,
			data->render.image_height, data->window_title);
	hooks_init(data->render.mlx_instance, data->render.mlx_window, data);
	mlx_loop(data->render.mlx_instance);
	return (0);
}

// * data->door_closed is no longer usable (doors v2 changed to invisible)
// * 	it can be good to add a 'toggle_invisible_wall'
// * 	or something like that in the future
static void	init_textures(void *mlx_instance, t_data *data)
{
	data->wall_north = open_image(mlx_instance, data->map.no_path, 64, 64);
	data->wall_south = open_image(mlx_instance, data->map.so_path, 64, 64);
	data->wall_east = open_image(mlx_instance, data->map.ea_path, 64, 64);
	data->wall_east.brightness = 8355711;
	data->wall_west = open_image(mlx_instance, data->map.we_path, 64, 64);
	data->wall_west.brightness = 8355711;
	if (data->raycasting.textured_ceiling)
	{
		data->ceiling_texture = open_image(
				mlx_instance, data->map.ceiling_path, 64, 64);
	}
	data->ceiling_texture.brightness = 8355711;
	if (data->raycasting.textured_floor)
	{
		data->floor_texture = open_image(
				mlx_instance, data->map.floor_path, 64, 64);
	}
}
