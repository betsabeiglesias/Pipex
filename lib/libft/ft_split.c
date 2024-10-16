/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betsabe <betsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:25:18 by beiglesi          #+#    #+#             */
/*   Updated: 2024/05/12 13:22:49 by betsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	count_splits(char const *s, char c)
{
	size_t	split;
	int		in_split;

	split = 0;
	in_split = 0;
	if (s == NULL || *s == '\0')
		split = 0;
	while (*s != '\0')
	{
		if (*s == c)
			in_split = 0;
		else
		{
			if (in_split == 0)
			{
				split++;
				in_split = 1;
			}
		}
		s++;
	}
	return (split);
}

static size_t	count_split_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	**free_matrix(char **matrix, size_t len_matrix)
{
	while (len_matrix--)
		free((void *)matrix[len_matrix]);
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	size_t	i;
	size_t	j;
	size_t	subs_len;

	i = 0;
	j = 0;
	matrix = (char **)malloc((count_splits(s, c) + 1) * sizeof(char *));
	if (!matrix || !s)
		return (NULL);
	while (i < count_splits(s, c))
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		if (s[j] != c && s[j] != '\0')
			subs_len = count_split_len(s + j, c);
		matrix[i] = (char *)malloc((subs_len + 1) * sizeof(char));
		if (!matrix[i])
			return (free_matrix(matrix, i));
		ft_strlcpy(matrix[i], s + j, subs_len + 1);
		i++;
		j = j + subs_len;
	}
	matrix[i] = NULL;
	return (matrix);
}
// static size_t	words_count(char *s, char c)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 			i++;
// 		else if (*s == c && i != 0)
// 		{
// 			j++;
// 			i = 0;
// 		}
// 		s++;
// 	}
// 	if (i != 0)
// 		j++;
// 	return (j);
// }

// static char	*word(char *s, char c)
// {
// 	char	*buf;

// 	while (*s == c)
// 		s++;
// 	buf = s;
// 	while (*buf && *buf != c)
// 		buf++;
// 	*buf = '\0';
// 	return (ft_strdup(s));
// }

// static char	**free_arr(char **arr, char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	free(s);
// 	return (NULL);
// }

// static char	**worker(char **arr, char *s1, char c, size_t j)
// {
// 	size_t	i;
// 	char	*str;

// 	str = s1;
// 	i = 0;
// 	while (i < j)
// 	{
// 		if (*s1 != c)
// 		{
// 			arr[i] = word(s1, c);
// 			if (!arr[i])
// 				return (free_arr(arr, s1));
// 			s1 = s1 + ft_strlen(arr[i]);
// 			i++;
// 		}
// 		s1++;
// 	}
// 	arr[i] = NULL;
// 	free(str);
// 	return (arr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**w_arr;
// 	char	*s1;
// 	size_t	j;

// 	s1 = ft_strdup(s);
// 	if (!s1)
// 		return (NULL);
// 	j = words_count(s1, c);
// 	w_arr = (char **)malloc(sizeof(char *) * (j + 1));
// 	if (!w_arr)
// 		return (NULL);
// 	return (worker(w_arr, s1, c, j));
// }