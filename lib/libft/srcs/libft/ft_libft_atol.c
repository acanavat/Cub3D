/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_atol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:05:44 by isibio            #+#    #+#             */
/*   Updated: 2023/03/28 14:07:52 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long	ft_atol(char *str)
{
	int		i;
	int		negative;
	long	nb;

	i = 0;
	negative = 1;
	nb = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (ft_memcmp((char *)str, "9223372036854775807", 19) == 0)
		return (9223372036854775807);
	if (ft_memcmp((char *)str, "-9223372036854775807", 20) == 0)
		return (-9223372036854775807);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * negative);
}
