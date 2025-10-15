/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:32:19 by isibio            #+#    #+#             */
/*   Updated: 2022/11/16 16:32:20 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*copy;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	copy = malloc(len + 1 * sizeof(char));
	if (!copy)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		copy[j++] = s1[i++];
	i = 0;
	while (s2[i])
		copy[j++] = s2[i++];
	copy[j] = '\0';
	return (copy);
}
