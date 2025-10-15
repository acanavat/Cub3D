/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanavat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:01:40 by acanavat          #+#    #+#             */
/*   Updated: 2024/04/04 19:03:27 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	parameter_in_file(char **str_file, t_data *data, int x, int y)
{
	int	count;

	count = 0;
	while (x < data->map.first_line)
	{
		while (str_file[x][y] == ' ' || str_file[x][y] == '\t')
			y++;
		if (str_file[x][y] == 'N' && str_file[x][y + 1] == 'O')
			count++;
		else if (str_file[x][y] == 'S' && str_file[x][y + 1] == 'O')
			count++;
		else if (str_file[x][y] == 'W' && str_file[x][y + 1] == 'E')
			count++;
		else if (str_file[x][y] == 'E' && str_file[x][y + 1] == 'A')
			count++;
		else if (str_file[x][y] == 'F' || str_file[x][y] == 'C')
			count++;
		else if (str_file[x][y] != '\n')
			return (1);
		x++;
		y = 0;
	}
	if (count != 6)
		return (1);
	return (0);
}

int	extention_cub(char *argv)
{
	int		x;
	char	*cub;

	cub = ".cub";
	x = 0;
	while (argv[x])
		x++;
	while (x > 0 && argv[x] != '.')
		x--;
	if (x == 0)
		return (1);
	if (ft_strncmp(&argv[x], cub, ft_strlen(&argv[x]) + 1) != 0)
		return (1);
	return (0);
}

void	parse(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		printf("error : invalid argument");
		exit(1);
	}
	if (extention_cub(argv[1]) == 1)
		exit_close(fd, "wrong file extension");
	fd = open(argv[1], O_DIRECTORY, 0777);
	if (fd != -1)
		exit_close(fd, "file not found");
	fd = open(argv[1], O_RDONLY, 0777);
	if (fd == -1)
		exit_close(fd, "file not found");
	close(fd);
}
