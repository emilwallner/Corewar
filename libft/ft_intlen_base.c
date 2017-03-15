/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:42:34 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 17:36:43 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uintlen_base(unsigned long n, int base)
{
	size_t			i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

size_t	ft_intlen_base(long long n, int base)
{
	size_t			i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}
