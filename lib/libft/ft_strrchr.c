/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beiglesi <beiglesi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:01:02 by betsabe           #+#    #+#             */
/*   Updated: 2024/01/15 11:54:51 by beiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *) s;
	while (len > 0)
	{
		if (str[len] == (unsigned char)c)
			return ((char *)&str[len]);
		len--;
	}
	if (str[len] == (unsigned char)c)
		return ((char *)&str[len]);
	return (NULL);
}
