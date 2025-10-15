/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:40:58 by isibio            #+#    #+#             */
/*   Updated: 2022/11/09 08:41:00 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!dst || !src) && !len)
		return (0);
	j = ft_strlen(dst);
	if (len <= j)
		return (len + ft_strlen(src));
	while (src[i] && j + 1 < len)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (j + ft_strlen(&src[i]));
}
