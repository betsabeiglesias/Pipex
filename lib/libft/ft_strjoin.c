/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:36:42 by beiglesi          #+#    #+#             */
/*   Updated: 2024/01/15 10:42:04 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str_join;

	if (s1 == NULL || s2 == NULL)
		return (0);
	else
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str_join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	if (!s1)
		ft_strlcpy(str_join, s2, len_s2 + 1);
	if (!s2)
		ft_strlcpy(str_join, s1, len_s1 + 1);
	else
		ft_strlcpy(str_join, s1, len_s1 + 1);
	ft_strlcat(str_join, (char *) s2, len_s1 + len_s2 + 1);
	return (str_join);
}
