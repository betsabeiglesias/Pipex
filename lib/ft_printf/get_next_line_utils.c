/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betsabe <betsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:10:10 by beiglesi          #+#    #+#             */
/*   Updated: 2024/02/08 09:56:36 by betsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*dst;
	int		len_s;

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
	dst = malloc ((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	else
		ft_strlcpy(dst, s + start, (len + 1));
	dst[len] = '\0';
	return (dst);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	result;

	i = 0;
	result = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (result);
}

char	*ft_strchr( char *s, int c)
{
	if (!s || !c)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	lendst;
	int	lensrc;
	int	result;
	int	i;

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

char	*ft_gnljoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str_join;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str_join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	str_join[len_s1 + len_s2] = '\0';
	if (!str_join)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(str_join, s1, len_s1 + 1);
		ft_strlcat(str_join, (char *) s2, len_s1 + len_s2 + 1);
	}
	else
		ft_strlcpy(str_join, s2, len_s2 + 1);
	return (str_join);
}
