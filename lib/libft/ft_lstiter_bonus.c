/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:09:15 by betsabe           #+#    #+#             */
/*   Updated: 2024/01/21 13:39:00 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*#include <stdio.h>

void ft_any (void *s)
{
	printf("Funciona?: %s\n", (char *)s);
}


int main()
{
	t_list *list;
	t_list *original_list;
 	
	list = NULL;
 	ft_lstadd_back(&list,ft_lstnew("Domingos"));
	ft_lstadd_back(&list,ft_lstnew("picando"));
	ft_lstadd_back(&list,ft_lstnew("código"));

	original_list = list;

	while(original_list)
	{
		printf("%s\n", original_list->content);
		original_list = original_list->next;
	}

	ft_lstiter(list, ft_any);

	return (0);
}*/