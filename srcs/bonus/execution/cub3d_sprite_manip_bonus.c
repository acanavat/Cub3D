/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_sprite_manip.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:43:04 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 12:43:05 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

t_sprite	*new_sprite(
		double pos_x, double pos_y, double pos_z, int animation_speed)
{
	t_sprite	*to_return;

	to_return = malloc(sizeof(t_sprite));
	to_return->animation_speed = animation_speed;
	set_sprite_position(to_return, pos_x, pos_y, pos_z);
	to_return->frame = 0;
	to_return->animation_step = 0;
	to_return->animation_frames = 0;
	to_return->u_div = 1;
	to_return->v_div = 1;
	return (to_return);
}

void	destroy_sprite(t_sprite *sprite, void *mlx_instance)
{
	int	i;

	if (!sprite)
		return ;
	i = -1;
	while (++i < sprite->animation_frames)
		mlx_destroy_image(mlx_instance, sprite->image[i].img);
	free(sprite->image);
	free(sprite);
}

void	set_sprite_position(t_sprite *sprite, double x, double y, double z)
{
	sprite->pos_x = x;
	sprite->pos_y = y;
	sprite->pos_z = z;
	sprite->v_move = -z;
}

void	set_sprite_size(t_sprite *sprite, double width, double height)
{
	sprite->u_div = width;
	sprite->v_div = height;
}

void	add_sprite_frame(t_sprite *sprite, t_image new_frame)
{
	t_image	*backup;

	if (!sprite->animation_frames)
	{
		sprite->animation_frames++;
		sprite->image = malloc(sizeof(t_image));
		sprite->image[0] = new_frame;
	}
	else
	{
		backup = clone_image_arr(sprite->image, sprite->animation_frames,
				sizeof(t_image) * sprite->animation_frames);
		free(sprite->image);
		sprite->image = clone_image_arr(backup, sprite->animation_frames,
				sizeof(t_image) * (sprite->animation_frames + 1));
		free(backup);
		sprite->image[sprite->animation_frames] = new_frame;
		sprite->animation_frames++;
	}
}
