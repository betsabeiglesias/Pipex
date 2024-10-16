/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbasics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:42:12 by beiglesi          #+#    #+#             */
/*   Updated: 2024/01/27 12:24:45 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		nb = n * -1;
	}
	else
		nb = n;
	if (nb > 9)
		len += ft_putnbr (nb / 10);
	len += ft_putchar ((nb % 10) + 48);
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}
