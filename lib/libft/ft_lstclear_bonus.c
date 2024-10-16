/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:58:49 by betsabe           #+#    #+#             */
/*   Updated: 2024/01/21 13:41:29 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
}

/*
void delete(void *content)
{
    free(content);
}


int main()
{
	t_list *lst;
	
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("hola"));
	ft_lstadd_back(&lst, ft_lstnew("que"));
	ft_lstadd_back(&lst, ft_lstnew("tal"));

	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}

	ft_lstdelone(lst,*delete);
	if(lst == NULL)
		printf("Aplico ft_lstdelone y funciona");
	else 
		printf("Aplic ft_lstdelone y no funciona");

	return (0);
}
*/