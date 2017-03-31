/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:24:10 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/15 17:21:38 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char*)str;
	while (i < n)
	{
		if ((unsigned char)c == str2[i])
			return (str2 + i);
		i++;
	}
	return (NULL);
}
