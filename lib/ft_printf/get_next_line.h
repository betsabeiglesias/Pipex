/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: betsabe <betsabe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:19:34 by beiglesi          #+#    #+#             */
/*   Updated: 2024/02/08 10:05:15 by betsabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		ft_strlen( char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strchr(char *s, int c);
char	*ft_gnljoin(char *s1, char *s2);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlcat(char *dst, char *src, int dstsize);
char	*get_next_line(int fd);

#endif