/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_dir_manip.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 08:50:39 by isibio            #+#    #+#             */
/*   Updated: 2024/04/02 08:50:41 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	rotate_right(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(-rot_speed)
		- data->player.dir_y * sin(-rot_speed);
	data->player.dir_y = old_dir_x * sin(-rot_speed)
		+ data->player.dir_y * cos(-rot_speed);
	data->player.plane_x = data->player.plane_x * cos(-rot_speed)
		- data->player.plane_y * sin(-rot_speed);
	data->player.plane_y = old_plane_x * sin(-rot_speed)
		+ data->player.plane_y * cos(-rot_speed);
}

void	rotate_left(t_data *data, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(rot_speed)
		- data->player.dir_y * sin(rot_speed);
	data->player.dir_y = old_dir_x * sin(rot_speed)
		+ data->player.dir_y * cos(rot_speed);
	data->player.plane_x = data->player.plane_x * cos(rot_speed)
		- data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed)
		+ data->player.plane_y * cos(rot_speed);
}
