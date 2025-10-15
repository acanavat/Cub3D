/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_math_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:48:06 by isibio            #+#    #+#             */
/*   Updated: 2024/04/04 12:48:06 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

double	ft_dabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

// * /!\ VAR NOT A STRING
void	toggle(char *var)
{
	if (*var)
		*var = 0;
	else
		*var = 1;
}
