/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:14:30 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/15 17:45:29 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	const char		*src1;

	src1 = src;
	while (*src != '\0')
	{
		src++;
	}
	while (src != src1)
	{
		if (*src == c)
			return ((char*)src);
		src--;
	}
	if (*src == c)
		return ((char*)src);
	return (NULL);
}
