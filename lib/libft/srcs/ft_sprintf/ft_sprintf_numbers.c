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

#include "../../includes/ft_sprintf.h"

static int	handle_sign(double *number);

int			ft_putnbr(int n);
int			ft_putunbr(unsigned int n);

char	*fts_flag_d(int number)
{
	return (ft_itoa(number));
}

char	*fts_flag_i(int number)
{
	return (ft_itoa(number));
}

char	*fts_flag_u(unsigned int number)
{
	return (ft_itoa(number));
}

/*
	[break condition] !(int)(number_calc * 10000) :
		- gives the max number of '0' after the .
*/
char	*fts_flag_f(double number)
{
	double	number_calc;
	int		whole;
	char	*decimal;
	char	sign;
	int		i;

	if (!number)
		return (ft_ctos('0'));
	sign = handle_sign(&number);
	whole = number;
	number_calc = number - (int)number;
	if (!(int)(number_calc * 10000))
		return (ft_itoa(whole * sign));
	decimal = ft_ctos('\0');
	i = 0;
	while (++i || 1)
	{
		number_calc -= (int)number_calc;
		number_calc *= 10;
		if ((int)(number_calc + 0.1) >= 10 || !(int)(number_calc * 10000))
			break ;
		decimal = ft_freejoin(decimal, ft_itoa(number_calc + 0.1));
	}
	return (ft_freejoin(ft_itoa(whole * sign),
			ft_freejoin(ft_ctos('.'), decimal)));
}

static int	handle_sign(double *number)
{
	int	sign;

	sign = 1;
	if (*number < 0 && --sign == 0 && --sign)
		*number *= -1;
	return (sign);
}
