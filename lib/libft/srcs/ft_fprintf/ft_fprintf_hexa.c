/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:46:52 by isibio            #+#    #+#             */
/*   Updated: 2022/12/07 15:46:53 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fprintf.h"

int		fp_flag_x(int fd, unsigned int number);
int		fp_flag_x2(int fd, unsigned int number);
int		fp_flag_p(int fd, unsigned long long c);
int		fp_flag_ull(int fd, unsigned long long number);

int	fp_flag_x(int fd, unsigned int number)
{
	int	ret;

	ret = 0;
	if (number >= 16)
	{
		ret += fp_flag_x(fd, number / 16);
		ret += fp_flag_x(fd, number % 16);
	}
	if (number <= 9)
	{
		ft_putchar_fd(number + '0', fd);
		ret++;
	}
	else if (number > 9 && number < 16)
	{
		ft_putchar_fd((number - 10) + 'a', fd);
		ret++;
	}
	return (ret);
}

int	fp_flag_x2(int fd, unsigned int number)
{
	int	ret;

	ret = 0;
	if (number >= 16)
	{
		ret += fp_flag_x2(fd, number / 16);
		ret += fp_flag_x2(fd, number % 16);
	}
	if (number <= 9)
	{
		ft_putchar_fd(number + '0', fd);
		ret++;
	}
	else if (number > 9 && number < 16)
	{
		ft_putchar_fd((number - 10) + 'A', fd);
		ret++;
	}
	return (ret);
}

int	fp_flag_p(int fd, unsigned long long c)
{
	int	ret;

	ret = 0;
	if (c == 0)
	{
		write(fd, "0x0", 3);
		return (3);
	}
	write(fd, "0x", 2);
	ret += fp_flag_ull(fd, c) + 2;
	return (ret);
}

int	fp_flag_ull(int fd, unsigned long long number)
{
	int	ret;

	ret = 0;
	if (number >= 16)
	{
		ret += fp_flag_ull(fd, number / 16);
		ret += fp_flag_ull(fd, number % 16);
	}
	if (number <= 9)
	{
		ft_putchar_fd(number + '0', fd);
		ret++;
	}
	else if (number > 9 && number <= 15)
	{
		ft_putchar_fd((number - 10) + 'a', fd);
		ret++;
	}
	return (ret);
}
