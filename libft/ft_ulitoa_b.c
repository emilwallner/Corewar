/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:21:11 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 17:43:42 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_findchar(uintmax_t value, int base)
{
	if (value % base < 10)
		return ('0' + (value % base));
	else
		return ('a' - 10 + (value % base));
}

char		*ft_ulitoa_b(uintmax_t value, int base)
{
	size_t			size;
	size_t			i;
	char			*tmp;

	size = ft_uintlen_base(value, base);
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
