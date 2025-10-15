/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanavat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:11:36 by acanavat          #+#    #+#             */
/*   Updated: 2024/04/04 18:14:53 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	skip_space_tab(char *str, int y)
{
	while (str[y] == ' ' || str[y] == '\t')
		y++;
	return (y);
}

void	exit_close(int fd, char *str)
{
	if (fd != 0)
		close(fd);
	printf("error : %s\n", str);
	exit(1);
}

void	free_tab_tab(char **str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		free(str[x]);
		x++;
	}
	free(str);
}

void	free_exit(char **str, char **map, char *error_msg)
{
	if (str)
		free_tab_tab(str);
	if (map)
		free_tab_tab(map);
	printf("error : %s\n", error_msg);
	exit (1);
}

void	exit_for_texture(char **str, char *path, int fd)
{
	free_tab_tab(str);
	close(fd);
	free(path);
	printf("invalid texture\n");
	exit(1);
}
