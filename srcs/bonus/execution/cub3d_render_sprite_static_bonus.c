/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_sprite_static.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:12:24 by isibio            #+#    #+#             */
/*   Updated: 2024/04/05 08:12:27 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"
#include "../../../include/cub3d_render_sprite_static_bonus.h"

// * Could be more permissive if the invisible color inside 't_sprite'
void	sprite_draw(t_data *data, t_sprite *sprite, t_sprie_cast sprite_cast)
{
	int	color;

	sprite_cast.stripe = sprite_cast.draw_start_x - 1;
	while (++sprite_cast.stripe < sprite_cast.draw_end_x)
	{
		if (sprite_cast.transform_y > 0 && sprite_cast.stripe > 0
			&& sprite_cast.stripe < (int)data->render.image_width
			&& sprite_cast.transform_y
			< data->raycasting.z_buffer[sprite_cast.stripe])
		{
			sprite_cast.y = sprite_cast.draw_start_y - 1;
			while (++sprite_cast.y < sprite_cast.draw_end_y)
			{
				color = pick_good_sprite_color(data, sprite, sprite_cast);
				if (sprite->image[sprite->animation_step].brightness)
					color = (color >> 1) & mlx_get_color_value(
							data->render.mlx_instance,
							sprite->image[sprite->animation_step].brightness);
				if (color != -16777216)
					pixel_put(data->render,
						sprite_cast.stripe, sprite_cast.y, color);
			}
		}
	}
}

unsigned int	pick_good_sprite_color(
	t_data *data, t_sprite *sprite, t_sprie_cast sprite_cast)
{
	int	d;
	int	tex_y;
	int	tex_x;

	d = (sprite_cast.y - sprite_cast.v_move_screen) * 256
		- data->render.image_height * 128 + sprite_cast.sprite_height * 128;
	tex_y = ((d * sprite->image[sprite->animation_step].image_height)
			/ sprite_cast.sprite_height) / 256;
	tex_x = (int)(256 * (sprite_cast.stripe - (-sprite_cast.sprite_width / 2
					+ sprite_cast.sprite_screen_x))
			* sprite->image[sprite->animation_step].image_width
			/ sprite_cast.sprite_width) / 256;
	return (pixel_get(sprite->image[sprite->animation_step], tex_x, tex_y));
}

void	sprite_frame_refresh(t_sprite *sprite)
{
	sprite->frame++;
	if (sprite->frame % sprite->animation_speed == 0)
		sprite->animation_step++;
	if (sprite->animation_step == sprite->animation_frames)
	{
		sprite->frame = 0;
		sprite->animation_step = 0;
	}
}

void	sprite_draw_init(
	t_data *data, t_sprite *sprite, t_sprie_cast *sprite_cast)
{
	if (sprite_cast->draw_start_y < 0)
		sprite_cast->draw_start_y = 0;
	sprite_cast->draw_end_y = sprite_cast->sprite_height / 2
		+ data->render.image_height / 2 + sprite_cast->v_move_screen;
	if (sprite_cast->draw_end_y >= (int)data->render.image_height)
		sprite_cast->draw_end_y = data->render.image_height - 1;
	sprite_cast->sprite_width = abs((int)(data->render.image_height
				/ (sprite_cast->transform_y))) / sprite->u_div;
	sprite_cast->draw_start_x = -sprite_cast->sprite_width / 2
		+ sprite_cast->sprite_screen_x;
	if (sprite_cast->draw_start_x < 0)
		sprite_cast->draw_start_x = 0;
	sprite_cast->draw_end_x = sprite_cast->sprite_width / 2
		+ sprite_cast->sprite_screen_x;
	if (sprite_cast->draw_end_x >= (int)data->render.image_width)
		sprite_cast->draw_end_x = data->render.image_width - 1;
}

void	sprite_cast_init(
	t_data *data, t_sprite *sprite, t_sprie_cast *sprite_cast)
{
	sprite_cast->sprite_x = sprite->pos_x - data->player.pos_x;
	sprite_cast->sprite_y = sprite->pos_y - data->player.pos_y;
	sprite_cast->inv_det = 1.0 / (data->player.plane_x * data->player.dir_y
			- data->player.dir_x * data->player.plane_y);
	sprite_cast->transform_x = sprite_cast->inv_det * (data->player.dir_y
			* sprite_cast->sprite_x - data->player.dir_x
			* sprite_cast->sprite_y);
	sprite_cast->transform_y = sprite_cast->inv_det * (-data->player.plane_y
			* sprite_cast->sprite_x + data->player.plane_x
			* sprite_cast->sprite_y);
	sprite_cast->sprite_screen_x = (int)((data->render.image_width / 2)
			* (1 + sprite_cast->transform_x / sprite_cast->transform_y));
	sprite_cast->v_move_screen = (int)(sprite->v_move
			/ sprite_cast->transform_y) + data->player.pitch
		+ data->player.pos_z / sprite_cast->transform_y;
	sprite_cast->sprite_height = abs((int)(data->render.image_height
				/ (sprite_cast->transform_y))) / sprite->v_div;
	sprite_cast->draw_start_y = -sprite_cast->sprite_height / 2
		+ data->render.image_height / 2 + sprite_cast->v_move_screen;
}
