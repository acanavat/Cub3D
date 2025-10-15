/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_direction_manip.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:26:33 by isibio            #+#    #+#             */
/*   Updated: 2024/04/02 08:26:34 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	set_player_position(t_player *player, double x, double y, double z)
{
	player->pos_x = x;
	player->pos_y = y;
	player->pos_z = z;
}

void	set_default_player_position(t_player *player,
	double x, double y, double z)
{
	player->default_pos_x = x;
	player->default_pos_y = y;
	player->default_pos_z = z;
}

void	reset_player_to_default(t_player *player)
{
	player->pitch = player->default_pitch;
	player->pos_x = player->default_pos_x;
	player->pos_y = player->default_pos_y;
	player->pos_z = player->default_pos_z;
	player->dir_x = player->default_dir_x;
	player->dir_y = player->default_dir_y;
	player->plane_x = player->default_plane_x;
	player->plane_y = player->default_plane_y;
	player->pointed_wall_dir = '/';
	player->gravity_phase = 0;
	player->rot_speed = player->default_rot_speed;
	player->move_speed = player->default_move_speed;
	player->mouse_speed = player->default_mouse_speed;
	player->range = 2;
}
