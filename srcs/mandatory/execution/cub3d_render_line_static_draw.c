/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_line_static_draw.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:36:46 by isibio            #+#    #+#             */
/*   Updated: 2024/04/05 08:36:47 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../include/cub3d_render_line_static.h"

static unsigned int	get_default_color(int side);

void	draw_line(t_image *render, t_data *data, t_line line_cast, int x)
{
	unsigned int	color;
	int				y;
	int				tex_y;

	line_cast.tex_num = data->map.tab_map
	[data->raycasting.map_x][data->raycasting.map_y];
	line_cast.step = 1.0 * line_cast.texture_height
		/ data->raycasting.line_length;
	line_cast.tex_pos = (data->raycasting.draw_start - (int)data->player.pitch
			- (data->player.pos_z / data->raycasting.perp_wall_dist)
			- data->render.image_height / 2 + data->raycasting.line_length / 2)
		* line_cast.step;
	y = data->raycasting.draw_start - 1;
	while (++y <= data->raycasting.line_end)
	{
		tex_y = (unsigned int)
			line_cast.tex_pos & (line_cast.texture_height - 1);
		line_cast.tex_pos += line_cast.step;
		color = pick_good_wall_color(data, line_cast, tex_y);
		if (data->toggle_render_walls)
			pixel_put(*render, x, y, color);
	}
}

// * this func can be moved to replace the pick_good_wall_color() func call
// * 	-> replace 'return (X)' by 'color = X'
// * 	-> ramove listed new variables (decl && init) and replace them with :
// * 		-> add the prefix 'data->raycasting.' to 'map_x,map_y' vraiables
// * 		-> add the prefix 'line_cast.' to 'tex_x' vraiable
// * 		-> add the prefix 'data->render.' to 'mlx_instance' vraiable
int	pick_good_wall_color(t_data *data, t_line line_cast, int tex_y)
{
	int		map_x;
	int		map_y;
	char	wall_side;
	int		tex_x;
	void	*mlx_instance;

	map_x = data->raycasting.map_x;
	map_y = data->raycasting.map_y;
	wall_side = get_wall_side(
			data, data->map.tab_map[map_x][map_y], data->raycasting.side);
	tex_x = line_cast.tex_x;
	mlx_instance = data->render.mlx_instance;
	if (wall_side == 'N')
		return (get_image_color(data->wall_north, mlx_instance, tex_x, tex_y));
	if (wall_side == 'S')
		return (get_image_color(data->wall_south, mlx_instance, tex_x, tex_y));
	if (wall_side == 'E')
		return (get_image_color(data->wall_east, mlx_instance, tex_x, tex_y));
	if (wall_side == 'W')
		return (get_image_color(data->wall_west, mlx_instance, tex_x, tex_y));
	return (get_default_color(!data->raycasting.side));
}

static unsigned int	get_default_color(int side)
{
	unsigned int	color;

	color = create_trgb(0, 255, 255, 255);
	if (side == 1)
		color /= 3;
	return (color);
}
