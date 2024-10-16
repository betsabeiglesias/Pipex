/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:56:51 by beiglesi          #+#    #+#             */
/*   Updated: 2024/01/15 12:18:09 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	result;
	size_t	i;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (dstsize <= lendst)
		result = (lensrc + dstsize);
	else
		result = (lensrc + lendst);
	if (dstsize != 0)
	{
		while (src[i] != '\0' && lendst < dstsize - 1)
		{
			dst[lendst] = src[i];
			i++;
			lendst++;
		}
	}
	dst[lendst] = '\0';
	return (result);
}
