/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:37:54 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 18:37:55 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static int	red_cross_hook(t_data *data);
static int	loop_hook(t_data *data);

void	hooks_init(void *mlx_instance, void *mlx_window, t_data *data)
{
	mlx_hook(mlx_window, 2, 1L << 0, pressed_key_hook, data);
	mlx_hook(mlx_window, 3, 1L << 1, released_key_hook, data);
	mlx_hook(mlx_window, 17, 1L << 17, red_cross_hook, data);
	mlx_loop_hook(mlx_instance, loop_hook, data);
}

// * this function call exit() in program_end(), the return is never call
// * 	-> done to respect the prototypes
// * 	   of functions called by mlx*_hook() (int)
static int	red_cross_hook(t_data *data)
{
	program_end(data);
	return (0);
}

static int	loop_hook(t_data *data)
{
	if (!data->toggle_pause)
	{
		execute_keys(data);
		exec(data);
	}
	else
		string_put_free(data, 12, data->render.image_height - 12,
			ft_sprintf("=== paused game ==="));
	return (0);
}
