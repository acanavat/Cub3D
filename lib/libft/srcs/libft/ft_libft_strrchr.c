/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:42:20 by isibio            #+#    #+#             */
/*   Updated: 2022/11/09 11:42:21 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s_copy;

	i = ft_strlen(s) + 1;
	s_copy = (char *)s;
	while (i-- > 0)
		if (s_copy[i] == (char)c)
			return (&s_copy[i]);
	return (0);
}
