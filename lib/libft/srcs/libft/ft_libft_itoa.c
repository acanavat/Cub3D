/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:47:50 by isibio            #+#    #+#             */
/*   Updated: 2022/11/18 11:47:52 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa(int n)
{
	char	*c;
	int		i;
	long	tmp;

	tmp = (long) n;
	i = ft_intlen(tmp);
	if (tmp < 0)
		tmp *= -1;
	c = malloc((ft_intlen((long) n) + 1) * sizeof(char));
	if (!c)
		return (0);
	if (n == 0)
		c[0] = '0';
	c[i] = '\0';
	i--;
	while (i >= 0)
	{
		c[i] = (tmp % 10) + '0';
		tmp = tmp / 10;
		i--;
	}
	if (n < 0)
		c[0] = '-';
	return (c);
}
