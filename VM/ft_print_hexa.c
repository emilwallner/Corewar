/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:04:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/18 18:16:24 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_print_hexa(char *str, int len)
{
	int i;
	int hex;

	i = 0;
	while(i < len)
	{
		hex = 0xFF & (*str);
		(hex <= 0xF) ? ft_printf("0%x", hex) : ft_printf("%x", hex);
		ft_putchar(' ');
		if ((i + 1) % (MEM_SIZE / 100) == 0)
			ft_printf("\n");
		str++;
		i++;
	}
}
