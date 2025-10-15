/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:16:29 by isibio            #+#    #+#             */
/*   Updated: 2023/01/03 11:16:34 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t eCount, size_t eSize);
void	ft_bzero(void *s, size_t n);

char	*ft_gnl_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*copy;

	copy = malloc(sizeof(char) * (len - start + 1));
	if (!copy)
		return (NULL);
	i = start;
	j = 0;
	while (j < len - start)
		copy[j++] = s[i++];
	copy[j] = '\0';
	if (start > 0)
		free(s);
	return (copy);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*copy;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
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
	return (free(s1), copy);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t eCount, size_t eSize)
{
	char	*c;

	if (eCount && eCount * eSize / eCount != eSize)
		return (0);
	c = malloc(eSize * eCount);
	if (c == 0)
		return (0);
	ft_bzero(c, eSize * eCount);
	return (c);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
