/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:45:20 by isibio            #+#    #+#             */
/*   Updated: 2022/11/09 12:45:35 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	size_t			i;

	if (n == 0)
		return (0);
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	i = 0;
	n -= 1;
	while (i != n)
	{
		if (s1_copy[i] != s2_copy[i])
			return (s1_copy[i] - s2_copy[i]);
		i++;
	}
	return (s1_copy[i] - s2_copy[i]);
}
