/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_background_static_bonus.h             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:25:31 by isibio            #+#    #+#             */
/*   Updated: 2024/04/05 08:25:32 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_BACKGROUND_STATIC_BONUS_H
# define CUB3D_RENDER_BACKGROUND_STATIC_BONUS_H

typedef struct s_background
{
	int		is_floor;
	float	cam_z;
	int		p;
	float	ray_dir_x_0;
	float	ray_dir_y_0;
	float	ray_dir_x_1;
	float	ray_dir_y_1;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_y;
	int		tx;
	int		ty;
	float	floor_x;
	float	floor_y;
}	t_background;

void			background_cast_init(
					t_data *data, t_background *back_cast, int y);
void			calculate_horizon(
					t_data *data, t_background *back_cast, int y);
void			get_good_texture_cos(t_data *data, t_background *back_cast);
unsigned int	pick_good_bkg_color(t_data *data, t_background back_cast);

#endif	// CUB3D_RENDER_BACKGROUND_STATIC_BONUS_H