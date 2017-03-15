/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:21:11 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/16 06:10:40 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_findchar(unsigned int value, int base)
{
	if (value % base < 10)
		return ('0' + (value % base));
	else
		return ('a' - 10 + (value % base));
}

char		*ft_uitoa_b(unsigned int value, int base)
{
	size_t			size;
	size_t			i;
	char			*tmp;

	size = ft_intlen_base(value, base);
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	tmp[size] = '\0';
	if (!value)
		tmp[0] = '0';
	i = size - 1;
	while (value)
	{
		tmp[i] = ft_findchar(value, base);
		value = value / base;
		i--;
	}
	return (tmp);
}
