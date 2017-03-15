/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:58:19 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/18 10:56:39 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long int n)
{
	size_t			size;
	char			*nbr;
	long long int	n_abs;
	size_t			i;

	if (n < -9223372036854775807)
		return ("-9223372036854775808");
	n_abs = n < 0 ? -n : n;
	size = n < 0 ? ft_intlen_base(n_abs, 10) + 1 : ft_intlen_base(n_abs, 10);
	if (!(nbr = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	nbr[size] = '\0';
	if (!n_abs)
		nbr[0] = '0';
	i = size - 1;
	while (n_abs)
	{
		nbr[i] = n_abs % 10 + '0';
		n_abs = n_abs / 10;
		i--;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
