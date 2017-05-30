/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:07:03 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 10:56:37 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "ft_print.h"

int		ft_size_of_intmax(intmax_t nb, t_vars *e)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		e->neg = 1;
		nb = -nb;
	}
	while (nb)
	{
		nb /= e->base;
		i++;
	}
	return (i);
}

int		ft_size_of_uintmax(uintmax_t nb, t_vars *e)
{
	int		i;

	if (nb == 0)
		return (1);
	if (e->type == OCTAL || e->type == UOCTAL)
		e->base = 8;
	else if (e->type == HEX || e->type == UHEX || e->type == POINTER)
		e->base = 16;
	else
		e->base = 10;
	i = 0;
	while (nb)
	{
		nb /= e->base;
		i++;
	}
	return (i);
}

char	*ft_atoi_uintmax(uintmax_t nb, t_vars *e)
{
	char		*sixteen;
	int			len;

	if (nb == 0)
		return ("0");
	if (e->type == UHEX || e->type == UOCTAL)
		sixteen = "0123456789ABCDEF";
	else
		sixteen = "0123456789abcdef";
	e->nb = malloc(sizeof(char) * (e->len + 1));
	e->nb[e->len] = '\0';
	len = e->len;
	while (nb)
	{
		e->nb[--len] = sixteen[nb % e->base];
		nb /= e->base;
	}
	return (e->nb);
}

char	*ft_atoi_intmax(intmax_t nb, t_vars *e)
{
	char		*sixteen;
	int			len;

	if (nb < -9223372036854775807)
		return ("9223372036854775808");
	if (nb == 0)
		return ("0");
	sixteen = "0123456789";
	e->nb = malloc(sizeof(char) * (e->len + 1));
	e->nb[e->len] = '\0';
	len = e->len;
	if (nb < 0)
		nb = -nb;
	while (nb)
	{
		e->nb[--len] = sixteen[nb % e->base];
		nb /= e->base;
	}
	return (e->nb);
}
