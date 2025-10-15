/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanavat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:40:30 by acanavat          #+#    #+#             */
/*   Updated: 2024/04/04 19:43:40 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

char	*ret(char *str_file, int c, int z)
{
	int		x;
	char	*new_str;

	x = 0;
	while (str_file[x])
	{
		x++;
		z++;
		if (str_file[x] == c)
			z--;
	}
	new_str = malloc(sizeof(char) * z + 1);
	z = 0;
	x = 0;
	while (str_file[x])
	{
		if (str_file[x] != c)
		{
			new_str[z] = str_file[x];
			z++;
		}
		x++;
	}
	new_str[z] = '\0';
	return (new_str);
}

char	**ret_str(char *str_file)
{
	char	*tmp_str_1;
	char	*tmp_str_2;
	char	**str;
	int		z;

	z = 0;
	tmp_str_1 = ret(str_file, ' ', z);
	tmp_str_2 = ret(tmp_str_1, '\t', z);
	free(tmp_str_1);
	str = ft_split(tmp_str_2, ',');
	free(tmp_str_2);
	return (str);
}

void	stock_trgb(t_data *data, char str, char **rgb)
{
	if (!rgb[0] || !rgb[1] || !rgb[2])
		exit (1);
	if (str == 'F')
		data->floor_color = create_trgb(0, \
				ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	else
		data->ceiling_color = create_trgb(0, \
				ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
}

int	parse_floor_ceilling(char *str_file, int y, int z)
{
	char	**str;

	str = ret_str(str_file);
	y = 1;
	while (ft_isdigit(str[0][y]) == 1)
		y++;
	if (str[0][y] != '\0')
	{
		free_tab_tab(str);
		return (1);
	}
	y = 0;
	while (str[z])
	{
		while (ft_isdigit(str[z][y]) == 1)
			y++;
		if (str[z][y] != '\0' && str[z][y] != '\n')
		{
			free_tab_tab(str);
			return (1);
		}
		z++;
	}
	free_tab_tab(str);
	return (0);
}
