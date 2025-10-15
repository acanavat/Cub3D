/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_menu_debug_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:25:54 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 11:25:55 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

void	string_put_free(t_data *data, int x, int y, char *message)
{
	mlx_string_put(data->render.mlx_instance, data->render.mlx_window, x, y,
		create_trgb(0, 255, 255, 255), message);
	free(message);
}
