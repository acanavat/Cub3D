/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_image_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:58:41 by isibio            #+#    #+#             */
/*   Updated: 2024/04/01 17:58:44 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

t_image	open_image(void *mlx_instance, char *path, int width, int height)
{
	t_image	image;
	int		mlx_int;

	image.img = mlx_xpm_file_to_image(mlx_instance, path, &mlx_int, &mlx_int);
	if (!image.img)
	{
		printf("Error: can't open image '%s'\n", path);
		exit(1);
	}
	image.brightness = 0;
	image.image_width = width;
	image.image_height = height;
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	return (image);
}

int	get_image_color(t_image image, void *mlx_instance,
	unsigned int x, unsigned int y)
{
	int	color;

	color = pixel_get(image, x, y);
	if (image.brightness)
		color = (color >> 1)
			& mlx_get_color_value(mlx_instance, image.brightness);
	return (color);
}

t_image	*clone_image_arr(t_image *array, int nb_images, int malloc_size)
{
	t_image	*clone;
	int		i;

	i = -1;
	clone = malloc(malloc_size);
	while (++i < nb_images)
		clone[i] = array[i];
	return (clone);
}

void	get_image_resolution(int *width, int *height, t_image image)
{
	*width = image.image_width;
	*height = image.image_height;
}
