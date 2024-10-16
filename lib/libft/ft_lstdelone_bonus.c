/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:56:18 by betsabe           #+#    #+#             */
/*   Updated: 2024/01/21 13:43:04 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
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
