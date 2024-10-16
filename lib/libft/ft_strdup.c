/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:11:01 by beiglesi          #+#    #+#             */
/*   Updated: 2024/01/10 10:05:21 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen(s1) + 1;
	ptr = malloc(str_len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	else
		ft_strlcpy(ptr, s1, str_len);
	return ((char *) ptr);
}
