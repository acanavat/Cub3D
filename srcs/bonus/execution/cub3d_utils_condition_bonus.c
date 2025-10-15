/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_condition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:59:09 by isibio            #+#    #+#             */
/*   Updated: 2024/04/01 16:59:10 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

// return (1) if the ray can pass trough the object
int	is_foreground_object(char c)
{
	if (c == MAP_EMPTY || c == MAP_DOOR_OPEN)
		return (1);
	return (0);
}

int	is_invalid_printable_map_char(char c)
{
	return (c != MAP_WALL && c != MAP_DOOR_OPEN && c != MAP_DOOR_CLOSED);
}

int	is_door(char c)
{
	if (c == MAP_DOOR_CLOSED || c == MAP_DOOR_OPEN)
		return (1);
	return (0);
}

int	is_solid_wall(char c)
{
	if (c == MAP_EMPTY || c == MAP_DOOR_OPEN)
		return (0);
	return (1);
}

int	is_interactable_char(char c)
{
	if (c == MAP_DOOR_OPEN || c == MAP_DOOR_CLOSED)
		return (1);
	return (0);
}
