/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:11:02 by isibio            #+#    #+#             */
/*   Updated: 2022/11/09 11:42:16 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_copy;

	i = 0;
	s_copy = (char *)s;
	while (i < (int)ft_strlen(s) + 1)
	{
		if (s_copy[i] == (char)c)
			return (&s_copy[i]);
		i++;
	}
	return (0);
}
