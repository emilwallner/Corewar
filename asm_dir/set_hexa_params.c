/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 22:26:13 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/18 22:43:38 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	set_register(char *params, int fd, int *cursor)
{
	ft_putchar_fd(ft_atoi(params),fd);
	cursor +=1;
}

void	set_direct(t_op top, char *params, int fd, int *cursor)
{
	int	i;
	int	nb;

	i = 0;
	nb = ft_atoi(params);
	while (nb / 16)
		i++;
	i = -1;
	while (++i < 2 + 2 * top.label_size - 1)
	{
		ft_putchar_fd(0,fd);
		cursor +=1;
	}
	ft_putchar_fd(ft_atoi(params),fd);
	cursor +=1;

}

void	set_indirect(char *params, int fd, int *cursor)
{
	ft_putchar_fd(ft_atoi(params),fd);
	cursor +=1;
}
