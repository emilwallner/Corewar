/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:21:03 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/24 13:33:30 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nb, int base)
{
	if (nb == -2147483648)
	{
		ft_putnbr_base(nb / base, base);
		ft_putnbr_base(2147483648 % base, base);
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			if (base == 10)
				ft_putchar('-');
		}
		if (nb >= base)
		{
			ft_putnbr_base(nb / base, base);
			ft_putnbr_base(nb % base, base);
		}
		if (nb >= 0 && nb < 10)
			ft_putchar(nb + '0');
		if (nb >= 0 && nb >= 10 && nb < base)
			ft_putchar(nb + 'a' - 10);
	}
}
