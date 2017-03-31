/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:02:30 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 10:49:42 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_base(unsigned int i, unsigned int base_length, char *base)
{
	if (i > base_length)
	{
		ft_base(i / base_length, base_length, base);
		ft_base(i % base_length, base_length, base);
	}
	else
		ft_putchar(base[i]);
}
