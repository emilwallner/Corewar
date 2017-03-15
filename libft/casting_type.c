/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:48:57 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 10:39:01 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cast_type2(t_flags *f, va_list ap, int *tl)
{
	int tmp;

	if (ft_strchr("S", f->type))
		*tl += ft_wputstr(va_arg(ap, wchar_t*));
	else if (ft_strchr("s", f->type))
		return (ft_conv_alpha(va_arg(ap, char*), f));
	else if (f->type == 'p')
		return (ft_conv_num(ft_ulitoa_b(va_arg(ap, unsigned long), 16), f));
	else if (ft_strchr("c", f->type))
		return (ft_conv_alpha(ft_ctoa(va_arg(ap, wchar_t)), f));
	else if (ft_strchr("C", f->type))
	{
		tmp = *tl;
		*tl += ft_wputstr(ft_wctoa(va_arg(ap, wint_t)));
		*tl = tmp == *tl ? *tl + 1 : *tl;
	}
	return (NULL);
}

char	*ft_cast_type(t_flags *f, va_list ap, int base, int *tl)
{
	if (ft_strchr("dDi", f->type))
		if (f->ic != J)
			return (ft_conv_num(ft_itoa(va_arg(ap, int)), f));
		else
			return (ft_itoa(va_arg(ap, long long)));
	else if (ft_strchr("uoxX", f->type))
		if (f->ic != J)
			return (ft_conv_num(ft_uitoa_b(va_arg(ap, unsigned int), base), f));
		else
			return (ft_conv_num(ft_ulitoa_b(va_arg(ap, uintmax_t), base), f));
	else if (ft_strchr("fFeEgGaA", f->type))
		return (ft_conv_num(va_arg(ap, char*), f));
	else
		return (ft_cast_type2(f, ap, tl));
	return (NULL);
}
