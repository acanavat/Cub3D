/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:49:58 by isibio            #+#    #+#             */
/*   Updated: 2022/12/07 15:49:59 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_sprintf.h"

char	fts_flag_c(const char c)
{
	return (c);
}

char	*fts_flag_s(const char *s)
{
	if (!s)
		return (ft_strdup("(null)"));
	return (ft_strdup(s));
}
