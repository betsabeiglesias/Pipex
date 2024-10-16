/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:48:33 by beiglesi          #+#    #+#             */
/*   Updated: 2024/05/03 13:41:09 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_puthex(unsigned long n, char format);
int		ft_putaddress(unsigned long ptr);
int		ft_format(va_list args, const char format);
int		ft_putunsigned(unsigned int n);
int		ft_printf(char const *str, ...);
char	*get_next_line(int fd);
#endif 