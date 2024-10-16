/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:27:29 by beiglesi          #+#    #+#             */
/*   Updated: 2024/01/27 12:36:02 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long ptr)
{
	int		len;
	char	format;

	format = 'x';
	len = 2;
	ft_putstr ("0x");
	if (!ptr)
	{
		write (1, "0", 1);
		len++;
		return (len);
	}
	else
		len += ft_puthex (ptr, format);
	return (len);
}
