/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:24:30 by ewallner          #+#    #+#             */
/*   Updated: 2017/01/19 11:58:47 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int		ft_flagconv(char *str)
{
	int		value;

	if (*str == 'h' && *(str + 1) == 'h')
		value = 1;
	else if (*str == 'h')
		value = 2;
	else if (*str == 'l' && *(str + 1) == 'l')
		value = 3;
	else if (*str == 'l')
		value = 4;
	else if (*str == 'j')
		value = 5;
	else
		value = 6;
	return (value);
}

void	ft_initialize_e(t_vars *e)
{
	e->align = 0;
	e->zero = 0;
	e->plus = 0;
	e->width = -1;
	e->pointlen = -1;
	e->percent = 0;
	e->neg = 0;
	e->f = -1;
	e->flags = 0;
	e->len = 0;
	e->type = -1;
	e->base = 10;
	e->printchar = 'E';
	e->printextra = 0;
	e->printminus = 0;
	e->printsign = '0';
	e->printlen = 0;
	e->hash = 0;
	e->printplus = 0;
	e->printspace = 0;
	e->printlastspace = 0;
	e->printzero = 0;
	e->printprefix = 0;
	e->nb = NULL;
}

int		ft_findtype(char *str)
{
	int		k;
	char	*types;

	k = 0;
	types = "idDsScC%pUOXxou";
	while (types[k] != '\0')
	{
		if (types[k] == *str)
			return (k);
		k++;
	}
	return (-1);
}

void	hash(t_vars *e)
{
	e->printprefix = TRUE;
	e->hash = TRUE;
}

char	*ft_printtype(char *str, t_vars *e)
{
	while (e->type == -1 && *str != '\0')
	{
		if (*str == '-')
			e->align = TRUE;
		else if (*str == '+')
			e->plus = TRUE;
		else if (*str == ' ')
			e->printspace = TRUE;
		else if (*str == '0' && e->pointlen == -1 && e->width == -1 && !e->zero)
			e->zero = TRUE;
		else if (*str == '#')
			hash(e);
		else if (ft_isdigit(*str) == TRUE && *str != '0' && e->pointlen \
				== -1 && e->width == -1)
			e->width = ft_atoi(str);
		else if (*str == '.' && e->pointlen == -1)
			e->pointlen = ft_atoi(str + 1);
		else if ((*str == 'h' || *str == 'j' || *str == 'z' || *str == 'l') \
				&& !e->flags)
			e->flags = ft_flagconv(str);
		else if (ft_findtype(str) != -1)
			e->type = ft_findtype(str);
		str++;
	}
	return (str);
}
