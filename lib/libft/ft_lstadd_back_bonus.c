/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:20:20 by betsabe           #+#    #+#             */
/*   Updated: 2024/01/21 13:44:53 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

/*int main()
{
	t_list *list;
	
	list = NULL;
	ft_lstadd_back(&list,ft_lstnew("hola"));
	ft_lstadd_back(&list,ft_lstnew("que"));
	ft_lstadd_back(&list,ft_lstnew("tal"));


	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}

	return (0);
}
*/