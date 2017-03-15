/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:48:57 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 10:39:08 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cast_alpha(t_flags *f, va_list ap, int *tl)
{
	int tmp;

	if (f->fc == INT)
		return (ft_conv_alpha(ft_ctoa((wint_t)va_arg(ap, int)), f));
	else if (f->fc == CHAR_PTR || f->type == 's')
		return (ft_conv_alpha(va_arg(ap, char*), f));
	else if (f->fc == WCHAR_T_PTR || f->type == 'S')
		*tl += ft_wputstr(ft_conv_walpha((wchar_t*)va_arg(ap, wchar_t*), f));
	else if (f->fc == WINT_T || f->type == 'C')
	{
		tmp = *tl;
		*tl += ft_wputstr(ft_conv_walpha(ft_wctoa(va_arg(ap, wchar_t)), f));
		*tl = tmp == *tl ? *tl + 1 : *tl;
	}
	return (NULL);
}

char	*ft_cast_digit(t_flags *flags, va_list ap)
{
	if (flags->fc == S_CHAR)
		return (ft_conv_num(ft_itoa((signed char)va_arg(ap, int)), flags));
	else if (flags->fc == SHORT_I)
		return (ft_conv_num(ft_itoa((short int)va_arg(ap, int)), flags));
	else if (flags->fc == LONG_I)
		return (ft_conv_num(ft_itoa(va_arg(ap, long int)), flags));
	else if (flags->fc == LONG_LONG_I)
		return (ft_conv_num(ft_itoa(va_arg(ap, long long)), flags));
	else if (flags->fc == INTMAX_T)
		return (ft_conv_num(ft_itoa((long)va_arg(ap, uintmax_t)), flags));
	return (NULL);
}

char	*ft_cast_digit_base(t_flags *flag, va_list ap, int base)
{
	if (flag->fc == U_CHAR)
		return (ft_conv_num(ft_uitoa_b((unsigned char)va_arg(ap, unsigned int),
		base), flag));
	else if (flag->fc == U_SHORT_I)
		return (ft_conv_num(ft_ulitoa_b((unsigned short int)
		va_arg(ap, unsigned int), base), flag));
	else if (flag->fc == U_LONG_I)
		return (ft_conv_num(ft_ulitoa_b(va_arg(ap, unsigned long), base),
		flag));
	else if (flag->fc == U_LONG_LONG_I)
		return (ft_conv_num(ft_ulitoa_b(va_arg(ap, unsigned long), base),
		flag));
	else if (flag->fc == U_INTMAX_T)
		return (ft_conv_num(ft_ulitoa_b(va_arg(ap, uintmax_t), base), flag));
	return (NULL);
}

char	*ft_cast_arg(t_flags *f, va_list ap, int *tl)
{
	int	base;

	base = 10;
	if (f->type == 'o')
		base = 8;
	else if (f->type == 'x' || f->type == 'X')
		base = 16;
	else if (ft_strchr("difFeEgGaA", f->type))
		base = 10;
	if ((!f->ic && !ft_strchr("sScC", f->type)) || ft_strchr("p", f->type) ||
	f->ic == J)
		return (ft_cast_type(f, ap, base, tl));
	else if ((f->fc >= INT && f->fc <= WCHAR_T_PTR))
		return (ft_cast_alpha(f, ap, tl));
	else if (f->fc >= S_CHAR && f->fc <= INTMAX_T)
		return (ft_cast_digit(f, ap));
	else if (f->fc >= U_INT && f->fc <= U_INTMAX_T)
		return (ft_cast_digit_base(f, ap, base));
	else if (f->ic == SIZE_T && ft_strchr("di", f->type))
		return (ft_conv_num(ft_itoa((size_t)va_arg(ap, size_t)), f));
	else if (f->ic == SIZE_T && ft_strchr("uoxX", f->type))
		return (ft_conv_num(ft_ulitoa_b((size_t)va_arg(ap, size_t), base), f));
	return (NULL);
}
