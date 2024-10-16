/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:09:45 by beiglesi          #+#    #+#             */
/*   Updated: 2024/01/10 12:29:50 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len_s < start)
	{
		len = 0;
		start = 0;
	}
	if ((len + start) > len_s)
		len = len_s - start;
	dst = (char *)malloc ((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	else
		ft_strlcpy(dst, s + start, (len + 1));
	dst[len] = '\0';
	return (dst);
}
