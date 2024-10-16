/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:47:53 by beiglesi          #+#    #+#             */
/*   Updated: 2024/01/13 17:16:24 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	find_digits(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str_nb;
	int				index;
	unsigned int	abs_nb;

	index = find_digits(n);
	str_nb = (char *)malloc((index + 1) * sizeof(char));
	if (!str_nb)
		return (NULL);
	str_nb[index] = '\0';
	if (n < 0)
	{
		abs_nb = -1 * n;
		str_nb[0] = '-';
	}
	else
		abs_nb = n;
	if (abs_nb == 0)
		str_nb[0] = '0';
	while (abs_nb > 0)
	{
		index--;
		str_nb[index] = (abs_nb % 10) + '0';
		abs_nb = abs_nb / 10;
	}
	return (str_nb);
}
