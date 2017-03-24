/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:07:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/24 16:09:01 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_cp_int(int int_start, t_env e)
{
	int i;
	int value;

	i = 4;
	value = 0;
	while (--i >= 0)
		value += e.a[int_start + (3 - i)].hex << (i * 8);
	return (value);
}
