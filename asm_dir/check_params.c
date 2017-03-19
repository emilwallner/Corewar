/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:58:11 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/19 15:54:51 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	count_params(char *params, t_op top)
{
	int	i;
	int	comas;

	i = -1;
	comas = 1;
	while (params[++i])
		if (params[i] == SEPARATOR_CHAR)
			comas++;
	// ft_putnbr(comas);
	// ft_putstr(" = comas\n");
	// ft_putnbr(top.nb_params);
	// ft_putstr(" = top\n");
	if (comas != top.nb_params)
		return (0);
	return (1);
}

int			check_params(char *params, t_op top, t_asm *tasm)
{
	int	i;
	int	p;

	// ft_putstr("bbb\n");
	if (!count_params(params, top))
		return (0);
	i = 0;
	p = 0;
	printf("\nparametres = %i\n", top.nb_params);
	ft_putstr(params);
	while (params[i] && p < top.nb_params)
	{
		ft_putstr("bbbb\n");
		if (params[i] == 'r' && !check_register(params + i, top, p))
		{
			ft_putstr("cccc\n");

			return (0);
		}
		else if (params[i] == DIRECT_CHAR &&
			!check_direct(params + i, top, p, tasm))
			{
				ft_putstr("ddd\n");

			return (0);
		}
		else if (params[i] != DIRECT_CHAR && params[i] != 'r' &&
			!check_indirect(params + i, top, p, tasm))
		{
			// ft_putnbr(i);
			// ft_putstr("eee\n");
			return (0);
		}
		ft_putstr("fff\n");
		if (ft_strchr(params + i, SEPARATOR_CHAR))
			i += ft_strchr(params + i, SEPARATOR_CHAR) - (params + i) + 1;
		else
			i = ft_strlen(params);
			ft_putstr("\nfin check 1 params\n");
		p++;
	}
	ft_putstr("fin check params\n");
	return (1);
}
