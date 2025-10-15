/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:56:56 by isibio            #+#    #+#             */
/*   Updated: 2022/11/16 08:56:58 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*copy;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) > len + 1)
		copy = malloc(sizeof(char) * len + 1);
	else
		copy = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (!copy)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[start])
	{
		copy[j] = s[start];
		j++;
		start++;
	}
	copy[j] = '\0';
	return (copy);
}
