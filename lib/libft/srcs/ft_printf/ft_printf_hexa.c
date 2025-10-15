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

#include "../../includes/ft_printf.h"

int		flag_x(unsigned int number);
int		flag_x2(unsigned int number);
int		flag_p(unsigned long long c);
int		flag_ull(unsigned long long number);

int	flag_x(unsigned int number)
{
	int	ret;

	ret = 0;
	if (number >= 16)
	{
		ret += flag_x(number / 16);
		ret += flag_x(number % 16);
	}
	if (number <= 9)
	{
		ft_putchar_fd(number + '0', 1);
		ret++;
	}
	else if (number > 9 && number < 16)
	{
		ft_putchar_fd((number - 10) + 'a', 1);
		ret++;
	}
	return (ret);
}

int	flag_x2(unsigned int number)
{
	int	ret;

	ret = 0;
	if (number >= 16)
	{
		ret += flag_x2(number / 16);
		ret += flag_x2(number % 16);
	}
	if (number <= 9)
	{
		ft_putchar_fd(number + '0', 1);
		ret++;
	}
	else if (number > 9 && number < 16)
	{
		ft_putchar_fd((number - 10) + 'A', 1);
		ret++;
	}
	return (ret);
}

int	flag_p(unsigned long long c)
{
	int	ret;

	ret = 0;
	if (c == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	ret += flag_ull(c) + 2;
	return (ret);
}

int	flag_ull(unsigned long long number)
{
	int	ret;

	ret = 0;
	if (number >= 16)
	{
		ret += flag_ull(number / 16);
		ret += flag_ull(number % 16);
	}
	if (number <= 9)
	{
		ft_putchar_fd(number + '0', 1);
		ret++;
	}
	else if (number > 9 && number <= 15)
	{
		ft_putchar_fd((number - 10) + 'a', 1);
		ret++;
	}
	return (ret);
}
