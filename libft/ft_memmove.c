/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:20:18 by ewallner          #+#    #+#             */
/*   Updated: 2017/02/11 15:58:13 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (dst > src)
	{
		i = len - 1;
		while (i + 1 > 0)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i--;
		}
		return (dst);
	}
	else
		i = 0;
	while (i < len)
	{
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dst);
}
