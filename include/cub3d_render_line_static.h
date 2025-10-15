/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_line_static.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:37:55 by isibio            #+#    #+#             */
/*   Updated: 2024/04/05 08:37:55 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_LINE_STATIC_H
# define CUB3D_RENDER_LINE_STATIC_H

typedef struct s_line
{
	double	step;
	double	wall_x;
	double	tex_pos;
	int		tex_x;
	int		tex_num;
	int		texture_width;
	int		texture_height;
}	t_line;

// * cub3d_render_line_static_draw.c
void	draw_line(t_image *render, t_data *data, t_line line_cast, int x);
int		pick_good_wall_color(t_data *data, t_line line_cast, int tex_y);

// * cub3d_render_line_static_getters.c
char	get_wall_side(t_data *data, char object, int side);
void	get_good_image_resolution(t_data *data, t_line *line_cast);
int		get_tex_x(t_raycasting raycasting, t_line *line_cast);
double	get_wall_x(t_data *data);

#endif	// CUB3D_RENDER_LINE_STATIC_H