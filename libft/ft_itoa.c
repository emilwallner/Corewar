/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:53:54 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/15 17:26:49 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_itoa_length(int n)
{
	int		i;
	int		neg;

	neg = 0;
	i = 1;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + neg + 1);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = ft_itoa_length(n);
	str = (char*)malloc(sizeof(*str) * (length));
	if (str == NULL)
		return (NULL);
	str[--length] = '\0';
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	while (length--)
	{
		str[length] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
