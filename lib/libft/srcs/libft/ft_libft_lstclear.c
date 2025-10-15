/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:41:10 by isibio            #+#    #+#             */
/*   Updated: 2023/02/09 10:41:34 by isibio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	(void) del;
	(void) lst;
}

/*
int main()
{
	t_list *list1 = ft_lstnew(1);
	t_list *list2 = ft_lstnew(2);
	t_list *list3 = ft_lstnew(3);
	t_list *list4 = ft_lstnew(4);
	t_list *list5 = ft_lstnew(5);
	t_list *list6 = ft_lstnew(6);
	t_list *list7 = ft_lstnew(7);
	t_list *list8 = ft_lstnew(8);
	t_list *list9 = ft_lstnew(9);
	t_list *list10 = ft_lstnew(10);

	ft_lstadd_front(&list10, list9);
	ft_lstadd_front(&list9, list8);
	ft_lstadd_front(&list8, list7);
	ft_lstadd_front(&list7, list6);
	ft_lstadd_front(&list6, list5);
	ft_lstadd_front(&list5, list4);	
	ft_lstadd_front(&list4, list3);
	ft_lstadd_front(&list3, list2);
	ft_lstadd_front(&list2, list1);

	printf("\nbefore -> ft_lstlast : %d\n", ft_lstlast(list1));
		printf("\tlist1->content \t= %d\n", list1->content);
		printf("\tlist1->next \t= %p\n\n", list1->next);

		printf("\tlist2->content \t= %d\n", list2->content);
		printf("\tlist2->next \t= %p\n\n", list2->next);
	
		printf("\tlist3->content \t= %d\n", list3->content);
		printf("\tlist3->next \t= %p\n\n", list3->next);
	
		printf("\tlist4->content \t= %d\n", list4->content);
		printf("\tlist4->next \t= %p\n\n", list4->next);
	
		printf("\tlist5->content \t= %d\n", list5->content);
		printf("\tlist5->next \t= %p\n\n", list5->next);
	
		printf("\tlist6->content \t= %d\n", list6->content);
		printf("\tlist6->next \t= %p\n\n", list6->next);
	
		printf("\tlist7->content \t= %d\n", list7->content);
		printf("\tlist7->next \t= %p\n\n", list7->next);
	
		printf("\tlist8->content \t= %d\n", list8->content);
		printf("\tlist8->next \t= %p\n\n", list8->next);
	
		printf("\tlist9->content \t= %d\n", list9->content);
		printf("\tlist9->next \t= %p\n\n", list9->next);
	
		printf("\tlist10->content = %d\n", list10->content);
		printf("\tlist10->next \t= %p\n\n", list10->next);

	ft_lstclear(&list5, NULL);

	printf("\n--------------------------------------------\n");
	printf("\nafter  -> ft_lstlast : %d\n", ft_lstlast(list1));
		printf("\tlist1->content \t= %d\n", list1->content);
		printf("\tlist1->next \t= %p\n\n", list1->next);
	
		printf("\tlist2->content \t= %d\n", list2->content);
		printf("\tlist2->next \t= %p\n\n", list2->next);
	
		printf("\tlist3->content \t= %d\n", list3->content);
		printf("\tlist3->next \t= %p\n\n", list3->next);
	
		printf("\tlist4->content \t= %d\n", list4->content);
		printf("\tlist4->next \t= %p\n\n", list4->next);
	
		printf("\tlist5->content \t= %d\n", list5->content);
		printf("\tlist5->next \t= %p\n\n", list5->next);
	
		printf("\tlist6->content \t= %d\n", list6->content);
		printf("\tlist6->next \t= %p\n\n", list6->next);
	
		printf("\tlist7->content \t= %d\n", list7->content);
		printf("\tlist7->next \t= %p\n\n", list7->next);
	
		printf("\tlist8->content \t= %d\n", list8->content);
		printf("\tlist8->next \t= %p\n\n", list8->next);
	
		printf("\tlist9->content \t= %d\n", list9->content);
		printf("\tlist9->next \t= %p\n\n", list9->next);
	
		printf("\tlist10->content = %d\n", list10->content);
		printf("\tlist10->next \t= %p\n\n", list10->next);

	return 0;
}
*/
