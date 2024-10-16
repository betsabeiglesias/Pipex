/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betsabe <betsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:29:50 by beiglesi          #+#    #+#             */
/*   Updated: 2024/02/08 16:58:39 by betsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readandstop(int fd, char *storage)
{
	int		readed;
	char	*buffer;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(storage, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (free(buffer), NULL);
		buffer[readed] = '\0';
		temp = ft_gnljoin(storage, buffer);
		free (storage);
		storage = temp;
	}
	free (buffer);
	return (storage);
}

char	*catch_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len_line;

	if (!*storage)
		return (NULL);
	ptr = ft_strchr(storage, '\n');
	if (!ptr)
		return (storage);
	len_line = ptr - storage + 1;
	line = ft_substr(storage, 0, len_line);
	if (!line)
	{
		free (storage);
		return (NULL);
	}
	return (line);
}

char	*recycle_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		finish;
	int		start;

	if (!*storage)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		free(storage);
		return (NULL);
	}
	start = ptr - storage + 1;
	finish = ft_strlen(storage) - start + 1;
	new_storage = ft_substr(storage, start, finish);
	if (!new_storage)
		return (free(storage), NULL);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	if (!stock)
	{
		stock = malloc (sizeof(char) * 1);
		if (!stock)
			return (NULL);
		stock[0] = '\0';
	}
	stock = readandstop(fd, stock);
	if (!stock)
		return (free(stock), NULL);
	line = catch_line(stock);
	stock = recycle_storage(stock);
	return (line);
}

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (1);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
