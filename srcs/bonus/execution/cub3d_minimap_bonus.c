/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:37:08 by isibio            #+#    #+#             */
/*   Updated: 2024/04/01 17:37:09 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d_bonus.h"

static unsigned int	pick_good_color(char object);
static void			print_player(t_image render, char **map,
						double player_x, double player_y);
static void			skip_map_objects(char **map, int i, int *j);

// * this function will draw minimap on 'render'
void	get_minimap(t_image render, char **map,
			double player_x, double player_y)
{
	unsigned int	color;
	int				square_size;
	int				i;
	int				j;

	i = 0;
	j = 0;
	square_size = 4;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			skip_map_objects(map, i, &j);
			color = pick_good_color(map[i][ft_strlen(map[i]) - j - 1]);
			draw_square(render, (render.image_width - 6) - j * square_size,
				2 + i * square_size, color);
			j++;
		}
		i++;
	}
	print_player(render, map, player_x, player_y);
}

static unsigned int	pick_good_color(char object)
{
	unsigned int	color;

	if (object == MAP_WALL)
		color = create_trgb(0, 0, 0, 0);
	else if (object == MAP_EMPTY)
		color = create_trgb(0, 127, 127, 127);
	else if (object == MAP_DOOR_OPEN)
		color = create_trgb(0, 0, 255, 0);
	else if (object == MAP_DOOR_CLOSED)
		color = create_trgb(0, 255, 0, 0);
	else
		color = create_trgb(0, 255, 255, 255);
	return (color);
}

// * remember to update 'square_size' variable
static void	print_player(t_image render, char **map,
				double player_x, double player_y)
{
	unsigned int	color;
	unsigned int	square_size;
	int				square_x;
	int				square_y;

	square_size = 4;
	color = create_trgb(0, 255, 0, 255);
	square_x = (render.image_width - 6)
		+ ((int)player_y - ft_strlen(map[(int)player_x]) + 1) * square_size;
	square_y = 2 + (int)player_x * square_size;
	draw_square(render, square_x, square_y, color);
}

static void	skip_map_objects(char **map, int i, int *j)
{
	while (map[i][*j])
	{
		if (map[i][ft_strlen(map[i]) - *j - 1] != MAP_VOID)
			break ;
		*j += 1;
	}
}
