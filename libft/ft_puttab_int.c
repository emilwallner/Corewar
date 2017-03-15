/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:51:08 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/14 21:09:17 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_int(int **tab, int size, int size2)
{
	int i;

	if (tab && tab[0])
	{
		i = -1;
		while (++i < size2)
		{
			ft_putints(tab[i], size);
			ft_putchar('\n');
		}
	}
}
