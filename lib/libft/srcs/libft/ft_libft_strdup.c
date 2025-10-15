/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:32:18 by isibio            #+#    #+#             */
/*   Updated: 2022/11/16 08:15:48 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	ft_strlcpy(copy, s1, ft_strlen(s1) + 2);
	if (copy && ft_strlen(copy) != ft_strlen(s1))
		return (0);
	return ((char *)copy);
}
