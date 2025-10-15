/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 08:08:21 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 08:08:22 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"
#include "../../../include/cub3d_render_sprite_static_bonus.h"

void	render_sprite(t_data *data, t_sprite *sprite)
{
	t_sprie_cast	sprite_cast;

	if (!data->sprite)
		return ;
	sprite_cast_init(data, sprite, &sprite_cast);
	sprite_draw_init(data, sprite, &sprite_cast);
	sprite_frame_refresh(sprite);
	if (data->toggle_render_sprites)
		sprite_draw(data, sprite, sprite_cast);
}
