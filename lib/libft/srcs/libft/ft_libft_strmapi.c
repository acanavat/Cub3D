/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:23:43 by isibio            #+#    #+#             */
/*   Updated: 2022/11/23 10:23:45 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ss;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	ss = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	while (i < ft_strlen(s))
	{
		ss[i] = (*f)(i, s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
