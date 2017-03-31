/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:39:16 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/15 17:37:17 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	i = 0;
	while (dest[i] && i < size)
		i++;
	length = i;
	while (src[i - length] && i < size - 1)
	{
		dest[i] = src[i - length];
		i++;
	}
	if (length < size)
		dest[i] = '\0';
	return (length + ft_strlen(src));
}
