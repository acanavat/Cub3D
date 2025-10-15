/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:26:58 by isibio            #+#    #+#             */
/*   Updated: 2023/02/08 15:31:32 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*stock ;

	i = 0;
	stock = lst;
	while (stock->next != NULL)
	{
		stock = stock->next;
		i++;
	}
	return (stock->content);
}
