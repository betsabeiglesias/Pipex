/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:07:09 by betsabe           #+#    #+#             */
/*   Updated: 2024/01/27 12:52:30 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char format)
{
	int		len;
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = 0;
	if (n > 15)
		len += ft_puthex (n / 16, format);
	ft_putchar (base[n % 16]);
	len++;
	return (len);
}
