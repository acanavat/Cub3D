/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_pos_manip.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:26:18 by isibio            #+#    #+#             */
/*   Updated: 2024/04/02 08:26:19 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	set_player_direction_ew(t_player *player, char direction);
static void	set_default_player_direction_ew(t_player *player, char direction);

void	set_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->plane_x = 0;
		player->plane_y = 0.66;
		player->dir_x = -1;
		player->dir_y = 0;
	}
	if (direction == 'S')
	{
		player->plane_x = 0;
		player->plane_y = -0.66;
		player->dir_x = 1;
		player->dir_y = 0;
	}
	set_player_direction_ew(player, direction);
}

// * Cutted for norm respect, can be moved inside the parent function
static void	set_player_direction_ew(t_player *player, char direction)
{
	if (direction == 'E')
	{
		player->plane_x = 0.66;
		player->plane_y = 0;
		player->dir_x = 0;
		player->dir_y = 1;
	}
	if (direction == 'W')
	{
		player->plane_x = -0.66;
		player->plane_y = 0;
		player->dir_x = 0;
		player->dir_y = -1;
	}
}

void	set_default_player_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->default_plane_x = 0;
		player->default_plane_y = 0.66;
		player->default_dir_x = -1;
		player->default_dir_y = 0;
	}
	if (direction == 'S')
	{
		player->default_plane_x = 0;
		player->default_plane_y = -0.66;
		player->default_dir_x = 1;
		player->default_dir_y = 0;
	}
	set_default_player_direction_ew(player, direction);
}

// * Cutted for norm respect, can be moved inside the parent function
static void	set_default_player_direction_ew(t_player *player, char direction)
{
	if (direction == 'E')
	{
		player->default_plane_x = 0.66;
		player->default_plane_y = 0;
		player->default_dir_x = 0;
		player->default_dir_y = 1;
	}
	if (direction == 'W')
	{
		player->default_plane_x = -0.66;
		player->default_plane_y = 0;
		player->default_dir_x = 0;
		player->default_dir_y = -1;
	}
}

void	respawn(t_data *data)
{
	reset_player_to_default(&data->player);
}
