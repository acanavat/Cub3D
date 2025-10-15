/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_menu_key_debug.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:53:56 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 12:00:43 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	print_movement_keys(t_data *data, int *origin_x, int *origin_y);
static void	print_special_keys(t_data *data, int *origin_x, int *origin_y);

void	print_debug_key_menu(t_data *data)
{
	int	origin_y;
	int	origin_x;

	origin_y = -2;
	origin_x = 2;
	print_movement_keys(data, &origin_x, &origin_y);
	origin_y += 12;
	print_special_keys(data, &origin_x, &origin_y);
}

static void	print_movement_keys(t_data *data, int *origin_x, int *origin_y)
{
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("rotate_up     = %d", data->key.rotate_up));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("rotate_down   = %d", data->key.rotate_down));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("rotate_left   = %d", data->key.rotate_left));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("rotate_right  = %d", data->key.rotate_right));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("move_forward  = %d", data->key.move_forward));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("move_backward = %d", data->key.move_backward));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("move_left     = %d", data->key.move_left));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("move_right    = %d", data->key.move_right));
}

static void	print_special_keys(t_data *data, int *origin_x, int *origin_y)
{
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("respawn       = %d", data->key.respawn));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("exit          = %d", data->key.exit));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("sprint        = %d", data->key.sprint));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("sneak         = %d", data->key.sneak));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("jump          = %d", data->key.jump));
}
