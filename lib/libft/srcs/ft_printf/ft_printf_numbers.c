/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:51:02 by isibio            #+#    #+#             */
/*   Updated: 2022/12/07 15:51:03 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	flag_d(int number);
int	flag_i(int number);
int	flag_u(unsigned int number);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);

int	flag_d(int number)
{
	int		res;

	res = ft_putnbr(number);
	return (res);
}

int	flag_i(int number)
{
	int		res;

	res = ft_putnbr(number);
	return (res);
}

int	flag_u(unsigned int number)
{
	int	res;

	res = ft_putunbr(number);
	return (res);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putnbr(n / 10);
		ft_putchar_fd('8', 1);
		i++;
		return (i);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		i += ft_putnbr(n * -1);
		return (i);
	}
	if (n >= 10)
		i += ft_putnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	i++;
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		i += ft_putnbr(n * -1);
		return (i);
	}
	if (n >= 10)
		i += ft_putnbr(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	i++;
	return (i);
}
