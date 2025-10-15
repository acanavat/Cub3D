/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:46:30 by isibio            #+#    #+#             */
/*   Updated: 2023/02/09 14:46:36 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_intlen(long l)
{
	long	count;

	count = 0;
	if (l < 0)
	{
		count ++;
		l *= -1;
	}
	if (l == 0)
		return (1);
	while (l > 0)
	{
		l = l / 10;
		count ++;
	}
	return (count);
}
