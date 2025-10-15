/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_line_static_getters.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:36:39 by isibio            #+#    #+#             */
/*   Updated: 2024/04/05 08:36:40 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../include/cub3d_render_line_static.h"

double	get_wall_x(t_data *data)
{
	double	wall_x;

	if (data->raycasting.side == 0)
		wall_x = data->player.pos_y
			+ data->raycasting.perp_wall_dist * data->raycasting.ray_dir_y;
	else
		wall_x = data->player.pos_x
			+ data->raycasting.perp_wall_dist * data->raycasting.ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

// * /!\ This function write inside the line_cast struct
void	get_good_image_resolution(t_data *data, t_line *line_cast)
{
	char	wall_side;
	int		texture_width;
	int		texture_height;

	wall_side = get_wall_side(data, data->map.tab_map[data->raycasting.map_x]
		[data->raycasting.map_y], data->raycasting.side);
	texture_width = DEFAULT_TEXTURE_WIDTH;
	texture_height = DEFAULT_TEXTURE_HEIGHT;
	if (wall_side == 'N')
		get_image_resolution(&texture_width, &texture_height, data->wall_north);
	else if (wall_side == 'S')
		get_image_resolution(&texture_width, &texture_height, data->wall_south);
	else if (wall_side == 'E')
		get_image_resolution(&texture_width, &texture_height, data->wall_east);
	else if (wall_side == 'W')
		get_image_resolution(&texture_width, &texture_height, data->wall_west);
	line_cast->texture_width = texture_height;
	line_cast->texture_height = texture_height;
}

int	get_tex_x(t_raycasting raycasting, t_line *line_cast)
{
	int	tex_x;

	tex_x = (int)(line_cast->wall_x * (double)line_cast->texture_width);
	if (raycasting.side == 0 && raycasting.ray_dir_x > 0)
		tex_x = line_cast->texture_width - tex_x - 1;
	if (raycasting.side == 1 && raycasting.ray_dir_y < 0)
		tex_x = line_cast->texture_width - tex_x - 1;
	return (tex_x);
}

// * Is better if the function does not take
// * 't_data' in arguments but just 't_raycasting'
// * -> the updated variation of this function can be used as global func
char	get_wall_side(t_data *data, char object, int side)
{
	if (object == MAP_WALL && side == 0 && data->raycasting.ray_dir_x < 0)
		return ('S');
	if (object == MAP_WALL && side == 0 && data->raycasting.ray_dir_x > 0)
		return ('N');
	if (object == MAP_WALL && side == 1 && data->raycasting.ray_dir_y < 0)
		return ('E');
	if (object == MAP_WALL && side == 1 && data->raycasting.ray_dir_y > 0)
		return ('W');
	return ('\0');
}
