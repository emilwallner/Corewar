/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 18:25:24 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_if_ox(t_arg *arg, t_flags *f)
{
	char	*prefix;
	size_t	pre_len;
	int		is_nul;

	pre_len = 0;
	is_nul = !ft_strcmp(arg->param, "0");
	if (f->type == 'X' || f->type == 'x' || f->type == 'p')
		pre_len = !is_nul || f->type == 'p' ? 2 : 0;
	else
		pre_len = is_nul || (f->hashtag && f->dot && f->precision) ? 0 : 1;
	prefix = ft_strnew(pre_len);
	if (f->hashtag || f->type == 'p')
		prefix = ft_strncpy(prefix, "0x", pre_len);
	if (f->type == 'X')
	{
		arg->param = ft_toupperstr(arg->param);
		prefix = ft_toupperstr(prefix);
	}
	arg->prefix = prefix;
	if ((!ft_strcmp(arg->param, "0") && f->type == 'o' && (!f->precision &&
		f->dot && !f->hashtag)) || (f->dot && !f->precision && f->type == 'p'))
		arg->param = "";
}

void	ft_cast(t_arg *arg, t_flags *f)
{
	if (ft_strchr("poxX", f->type))
		ft_if_ox(arg, f);
	else if (*arg->param != '-' && f->type != 'u' && (f->plus || f->space))
		ft_if_pluspace(arg, f);
	if (f->precision)
		ft_if_precision(arg, f);
	if (!ft_strcmp(arg->param, "0") && f->dot && !f->precision && f->type != 'o'
	&& (!f->fc || f->fc == U_INT))
		arg->param = "";
	if (f->width)
		ft_if_width(arg, f);
}

char	*ft_conv_num(char *param, t_flags *f)
{
	size_t	final_len;
	size_t	pre_len;
	size_t	p_len;
	char	*final_p;
	t_arg	*arg;

	if (!ft_strchr("poxX", f->type) && !f->hashtag && !f->zero && !f->dot &&
	!f->minus && !f->plus && !f->space && !f->width && !f->precision)
		return (param);
	arg = ft_memalloc(sizeof(arg));
	arg->param = ft_memalloc(sizeof(char) * (ft_strlen(param) + 1));
	arg->prefix = ft_memalloc(sizeof(char) + 1);
	arg->suffix = ft_memalloc(sizeof(char) + 1);
	arg->param = param;
	ft_cast(arg, f);
	pre_len = ft_strlen(arg->prefix);
	p_len = ft_strlen(arg->param);
	final_len = pre_len + p_len + ft_strlen(arg->suffix);
	final_p = ft_strnew(final_len);
	ft_strncpy(final_p, arg->prefix, pre_len);
	ft_strncpy(final_p + pre_len, arg->param, p_len);
	ft_strncpy(final_p + pre_len + p_len, arg->suffix, ft_strlen(arg->suffix));
	return (final_p);
}
