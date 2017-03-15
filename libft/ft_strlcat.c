/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:07:22 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/18 17:33:29 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	j;

	i = ft_strlen(dest);
	size = i + ft_strlen((char*)src);
	j = 0;
	if (n < i)
		return (ft_strlen((char*)src) + n);
	if (n > i + 1)
	{
		while (src[j] && j < n - i - 1)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	return (size);
}
