/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:35:53 by isibio            #+#    #+#             */
/*   Updated: 2022/11/09 12:35:55 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((!s1) || (!s2))
			return ((unsigned const char)s1[0] - (unsigned const char)s2[0]);
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
	}
	return (0);
}
