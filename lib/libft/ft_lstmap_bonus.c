/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:15:06 by betsabe           #+#    #+#             */
/*   Updated: 2024/01/21 13:35:42 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*result;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		result = f(lst -> content);
		node = ft_lstnew(result);
		if (!node)
		{
			del(result);
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

/*void free_content(void *content)
{
    free(content);
}


void *ft_capitalize (void *s)
{
	char *e;

	e = malloc(sizeof(char) * 3);
	e[0] = ((char *)s)[0];
	e[1] = ((char *)s)[1];
	e[2] = '\0';
	return(e);
}

#include <stdio.h>

int main()
{
	
	t_list *list;
 	t_list *current;

	list = NULL;

	ft_lstadd_back(&list,ft_lstnew("hola"));
	ft_lstadd_back(&list,ft_lstnew("que"));
	ft_lstadd_back(&list,ft_lstnew("tal"));

	current = ft_lstmap(list, ft_capitalize, free_content);
	while(current)
	{
		//write(1, (current->content) + '0',3);
		printf("%s\n", current->content);
		current = current->next;
	}		
	return(0);
}*/