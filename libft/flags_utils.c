/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:33:23 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 11:18:43 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	typeformat2(t_flags *e)
{
	if (e->type == 'U')
	{
		e->type = 'u';
		e->ic = L;
		e->fc = e->ic + 10;
	}
	else if (e->type == 'D')
	{
		e->type = 'd';
		e->ic = L;
		e->fc = e->ic;
	}
	else if (e->type == 'O')
	{
		e->type = 'o';
		e->ic = L;
		e->fc = e->ic + 10;
	}
}

void	typeformat(t_flags *e)
{
	if (ft_strchr("di", e->type))
		e->fc = e->ic;
	else if (ft_strchr("uoxX", e->type))
		e->fc = e->ic + 10;
	else if (e->type == 'c' && e->ic == 0)
		e->fc = INT;
	else if ((e->type == 'c' && e->ic == 3) || e->type == 'C')
	{
		e->type = 'C';
		e->fc = WINT_T;
	}
	else if (e->type == 's' && e->ic == 0)
		e->fc = CHAR_PTR;
	else if ((e->type == 's' && e->ic == 3) || e->type == 'S')
	{
		e->type = 'S';
		e->fc = WCHAR_T_PTR;
	}
	else if (e->type == 'p' && e->ic == 0)
		e->fc = VOID_PTR;
	else
		typeformat2(e);
}

void	ft_special_flags(char *str, t_flags *sflags)
{
	if (!strncmp(str, "ll", 2))
	{
		sflags->ic = LL;
		str = str + 1;
	}
	else if (!strncmp(str, "hh", 2))
	{
		sflags->ic = HH;
		str = str + 1;
	}
	else if (!strncmp(str, "h", 1))
		sflags->ic = H;
	else if (!strncmp(str, "l", 1))
		sflags->ic = L;
	else if (!strncmp(str, "j", 1))
		sflags->ic = J;
	else if (!strncmp(str, "z", 1))
		sflags->ic = Z;
}

void	ft_check_flags(t_flags *sflags, char *flags)
{
	if (sflags->type == '%' && !ft_isdigit(*flags) &&
	!ft_strchr(" .+-", *flags))
		sflags->percent = -1;
	if (sflags->type == '%' && *(flags + 1) && !ft_isdigit(*(flags + 1)) &&
	!ft_strchr(" .+-", *(flags + 1)))
		sflags->percent = -1;
	if (sflags->type != '%' && !ft_isdigit(*flags) &&
	!ft_strchr(" jzlh#.+-", *flags))
		sflags->is_invalid = 1;
	if (*flags == '#')
		sflags->hashtag += 1;
	if (*flags == '0' && !sflags->width && !sflags->precision)
		sflags->zero += 1;
	if (*flags == '-')
		sflags->minus += 1;
}

int		ft_set_flags(t_flags *sflags, char *flags, int len)
{
	if (sflags->type != '%')
		sflags->type = flags[len - 1];
	sflags->flags = flags;
	sflags->flags_len = ft_strlen(flags);
	while (*flags && *(flags + 1))
	{
		ft_check_flags(sflags, flags);
		if (*flags == '+')
			sflags->plus += 1;
		if (*flags == ' ')
			sflags->space += 1;
		if (ft_isdigit(*flags) && !sflags->width)
			sflags->width = ft_atoi(flags) > 0 ? ft_atoi(flags) : 0;
		if (*flags == '.')
		{
			sflags->dot += 1;
			sflags->precision = ft_atoi(++flags);
		}
		if (!sflags->ic)
			ft_special_flags(flags, sflags);
		flags++;
	}
	typeformat(sflags);
	return (1);
}
