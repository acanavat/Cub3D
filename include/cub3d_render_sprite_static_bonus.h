/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_sprite_static_bonus.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:11:45 by isibio            #+#    #+#             */
/*   Updated: 2024/04/05 08:11:49 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_SPRITE_STATIC_BONUS_H
# define CUB3D_RENDER_SPRITE_STATIC_BONUS_H

typedef struct s_sprie_cast
{
	double	inv_det;
	double	sprite_x;
	double	sprite_y;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		v_move_screen;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_y;
	int		draw_end_y;
	int		draw_start_x;
	int		draw_end_x;

	int		stripe;
	int		y;
}	t_sprie_cast;

void			sprite_cast_init(t_data *data, t_sprite *sprite,
					t_sprie_cast *sprite_cast);
void			sprite_draw_init(t_data *data, t_sprite *sprite,
					t_sprie_cast *sprite_cast);
void			sprite_frame_refresh(t_sprite *sprite);
void			sprite_draw(t_data *data, t_sprite *sprite,
					t_sprie_cast sprite_cast);
unsigned int	pick_good_sprite_color(t_data *data, t_sprite *sprite,
					t_sprie_cast sprite_cast);

#endif	// CUB3D_RENDER_SPRITE_STATIC_BONUS_H