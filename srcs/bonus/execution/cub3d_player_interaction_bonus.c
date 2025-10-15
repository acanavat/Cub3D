/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player_interaction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:38:00 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 12:38:01 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	interact(t_player *player, char **map)
{
	interact_with_doors(player, map);
}

void	interact_with_doors(t_player *player, char **map)
{
	if (player->pointed_wall_dist > player->range)
		return ;
	if (map[player->pointed_map_x][player->pointed_map_y] == MAP_DOOR_CLOSED)
		map[player->pointed_map_x][player->pointed_map_y] = MAP_DOOR_OPEN;
	else if (map[player->pointed_map_x][player->pointed_map_y] == MAP_DOOR_OPEN)
		map[player->pointed_map_x][player->pointed_map_y] = MAP_DOOR_CLOSED;
}
