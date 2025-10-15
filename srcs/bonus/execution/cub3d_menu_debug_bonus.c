/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_menu_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:25:40 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 11:25:41 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static void	print_player(t_data *data, int *origin_x, int *origin_y);
static void	print_player_pointed(t_data *data, int *origin_x, int *origin_y);
static void	print_misc(t_data *data, int *origin_x, int *origin_y);
static void	print_options(t_data *data, int *origin_x, int *origin_y);

void	print_debug_menu(t_data *data)
{
	int	origin_y;
	int	origin_x;

	origin_y = -2;
	origin_x = 2;
	print_player(data, &origin_x, &origin_y);
	origin_y += 12;
	print_player_pointed(data, &origin_x, &origin_y);
	origin_y += 12;
	print_misc(data, &origin_x, &origin_y);
	origin_y += 12;
	print_options(data, &origin_x, &origin_y);
}

static void	print_player(t_data *data, int *origin_x, int *origin_y)
{
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"player pos_x  = %f", (double)data->player.pos_x));
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"player pos_y  = %f", (double)data->player.pos_y));
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"player pos_z  = %f", (double)data->player.pos_z));
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"player dir_x  = %f", (double)data->player.dir_x));
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"player dir_y  = %f", (double)data->player.dir_y));
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"player pitch  = %d (%ff)",
			(int)data->player.pitch, (double)data->player.pitch));
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"gravity phase = %d", data->player.gravity_phase));
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"plane (x, y)  : %f, %f",
			(double)data->player.plane_x, (double)data->player.plane_y));
	*origin_y += 12;
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"player rot_speed  = %f", (double)data->player.rot_speed));
	string_put_free(data, *origin_x, *origin_y += 12, ft_sprintf(
			"player move_speed = %f", (double)data->player.move_speed));
}

static void	print_player_pointed(t_data *data, int *origin_x, int *origin_y)
{
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("pointed map x     : %d", data->player.pointed_map_x));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("pointed map y     : %d", data->player.pointed_map_y));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("pointed wall id   : %c", data->player.pointed_wall_id));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("pointed wall dir  : %c", data->player.pointed_wall_dir));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("pointed wall dist : %f",
			(double)data->player.pointed_wall_dist));
}

static void	print_misc(t_data *data, int *origin_x, int *origin_y)
{
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("resolution         : %d x %d",
			data->render.image_width, data->render.image_height));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_freejoin(ft_strdup("last pressed key   : "),
			ft_itoa(data->last_pressed_key)));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_freejoin(ft_strdup("last released key  : "),
			ft_itoa(data->last_released_key)));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_freejoin(ft_strdup("bool textured ceiling : "),
			ft_itoa(data->raycasting.textured_ceiling)));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_freejoin(ft_strdup("bool textured floor   : "),
			ft_itoa(data->raycasting.textured_floor)));
}

static void	print_options(t_data *data, int *origin_x, int *origin_y)
{
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("toggle pause             : %d",
			data->toggle_pause));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("toggle render walls      : %d",
			data->toggle_render_walls));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("toggle render background : %d",
			data->toggle_render_background));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("toggle render crossair   : %d",
			data->toggle_render_crossair));
	string_put_free(data, *origin_x, *origin_y += 12,
		ft_sprintf("toggle render sprites    : %d",
			data->toggle_render_sprites));
}
