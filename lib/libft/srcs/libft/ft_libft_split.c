/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:42:56 by isibio            #+#    #+#             */
/*   Updated: 2022/11/18 11:42:58 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_counti(char const *s, char c);
static char		**ft_countj(char **tabtab, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**tabtab;

	if (!s)
	{
		tabtab = malloc(sizeof(char) * 1);
		if (!tabtab)
			return (0);
		tabtab[0] = 0;
		return (tabtab);
	}
	tabtab = malloc(sizeof(char *) * (ft_counti(s, c) + 1));
	if (!tabtab)
		return (0);
	tabtab = ft_countj(tabtab, s, c);
	return (tabtab);
}

static size_t	ft_counti(char const *s, char c)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (s[i] == c)
		i++;
	if (s[i] != c || s[i + 1] == '\0')
		k++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			k++;
		i++;
	}
	if (s[0] == c && k > 0)
		k++;
	return (k);
}

static char	**ft_countj(char **tabtab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			tabtab [x] = ft_substr(s, j, i - j);
			x++;
		}
	}
	tabtab [x] = NULL;
	return (tabtab);
}
