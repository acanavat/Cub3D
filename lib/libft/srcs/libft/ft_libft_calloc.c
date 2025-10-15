/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:44:15 by isibio            #+#    #+#             */
/*   Updated: 2022/11/11 14:44:16 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t eCount, size_t eSize)
{
	char	*c;

	if (eCount && eCount * eSize / eCount != eSize)
		return (0);
	c = malloc(eSize * eCount);
	if (!c)
		return (0);
	ft_bzero(c, eSize * eCount);
	return (c);
}
