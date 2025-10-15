/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_gravity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:26:11 by isibio            #+#    #+#             */
/*   Updated: 2024/04/02 09:26:12 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static int		jump_overcap(t_player *player, double jump_height,
					double jump_speed, double origin_z);

void	jump(t_player *player, double jump_height,
			double jump_speed, double speed_boost)
{
	static double			origin_z;
	static double			actual_jump_speed;

	if (!origin_z && player->gravity_phase == 1)
		origin_z = player->pos_z;
	if (!actual_jump_speed)
		actual_jump_speed = jump_speed;
	if (player->gravity_phase == 1)
	{
		if (actual_jump_speed < 1
			|| jump_overcap(player, jump_height, actual_jump_speed, origin_z))
		{
			player->gravity_phase = -1;
			player->pos_z = origin_z + jump_height;
			origin_z = 0;
			actual_jump_speed = 0;
			return ;
		}
		if (player->move_speed + speed_boost <= 0.9)
			player->move_speed += speed_boost;
		player->pos_z *= actual_jump_speed;
		actual_jump_speed /= 1.02;
	}
}

static int	jump_overcap(t_player *player, double jump_height,
				double jump_speed, double origin_z)
{
	return (player->pos_z * jump_speed >= origin_z + jump_height);
}

void	handle_gravity(t_player *player, double origin_z, double fall_speed)
{
	if (player->gravity_phase == -1)
	{
		player->pos_z /= fall_speed;
		if (player->pos_z - origin_z <= fall_speed)
		{
			player->gravity_phase = 0;
			player->pos_z = origin_z;
		}
	}
}
