/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:21:11 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/14 17:19:28 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_findchar(unsigned long value, int base)
{
	if (value % base < 10)
		return ('0' + (value % base));
	else
		return ('a' - 10 + (value % base));
}

char		*ft_itoa_base(long value, int base)
{
	size_t			size;
	size_t			i;
	char			*tmp;
	unsigned long	u_value;

	u_value = value < 0 ? -value : value;
	size = (value < 0 && base == 10) ? ft_intlen_base(u_value, base) + 1 :
	ft_intlen_base(u_value, base);
	if (!(tmp = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	tmp[size] = '\0';
	if (!u_value)
		tmp[0] = '0';
	i = size - 1;
	while (u_value)
	{
		tmp[i] = ft_findchar(u_value, base);
		u_value = u_value / base;
		i--;
	}
	if (value < 0 && base == 10)
		tmp[0] = '-';
	return (tmp);
}
