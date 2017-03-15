/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:33:14 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/10 09:32:55 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_increment(char c, int base, int nb)
{
	nb *= base;
	if (c >= '0' && c <= '9')
		nb += c - '0';
	else if (c >= 'a' && c < 'a' + base - 10)
		nb += c - 'a' + 10;
	else if (c >= 'A' && c < 'A' + base - 10)
		nb += c - 'A' + 10;
	else
		return (0);
	return (nb);
}

int			ft_atoi_base(const char *str, int base)
{
	int	i;
	int nb;
	int	is_neg;

	i = 0;
	is_neg = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
	|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		nb = ft_increment(str[i], base, nb);
		i++;
	}
	if (is_neg)
		return (-nb);
	return (nb);
}
