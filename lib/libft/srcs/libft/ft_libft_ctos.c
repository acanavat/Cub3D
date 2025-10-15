/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:14:35 by isibio            #+#    #+#             */
/*   Updated: 2024/03/15 11:14:38 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_ctos(char c)
{
	char	*to_return;

	to_return = malloc(sizeof(char) * 2);
	to_return[0] = c;
	to_return[1] = '\0';
	return (to_return);
}
