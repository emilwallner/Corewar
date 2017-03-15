/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 11:25:12 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_if_pluspace(t_arg *arg, t_flags *f)
{
	char	*prefix;

	if (f->space)
	{
		prefix = ft_strnew(1);
		ft_memset(prefix, ' ', 1);
	}
	if (f->plus && f->type != 'u')
	{
		prefix = ft_strnew(1);
		ft_memset(prefix, '+', 1);
	}
	arg->prefix = prefix;
}

void	ft_if_to_add(t_arg *arg, t_flags *f, size_t pre_len, int to_add)
{
	char	*tmp;

	if (f->minus)
	{
		arg->suffix = ft_strnew((size_t)to_add);
		ft_memset(arg->suffix, ' ', (size_t)to_add);
	}
	else
	{
		tmp = ft_strnew((size_t)to_add + pre_len);
		if (f->zero && !f->precision)
		{
			ft_strncpy(tmp, arg->prefix, pre_len);
			ft_memset(tmp + pre_len, '0', to_add);
		}
		else
		{
			ft_memset(tmp, ' ', to_add);
			ft_strncpy(tmp + to_add, arg->prefix, pre_len);
		}
		arg->prefix = tmp;
	}
}

void	ft_if_width(t_arg *arg, t_flags *f)
{
	int		to_add;
	size_t	cur_len;
	size_t	pre_len;

	if (*arg->param == '-')
	{
		arg->param = arg->param + 1;
		arg->prefix = ft_strnew(1);
		ft_memset(arg->prefix, '-', 1);
	}
	pre_len = ft_strlen(arg->prefix);
	cur_len = pre_len + ft_strlen(arg->param);
	to_add = (int)f->width - (int)cur_len;
	if (to_add > 0)
		ft_if_to_add(arg, f, pre_len, to_add);
}

void	ft_if_precision(t_arg *arg, t_flags *f)
{
	size_t	new_len;
	size_t	p_len;
	char	*tmp;

	if (*arg->param == '-')
	{
		arg->param = arg->param + 1;
		arg->prefix = ft_strnew(1);
		ft_memset(arg->prefix, '-', 1);
	}
	p_len = ft_strlen(arg->param);
	new_len = (int)p_len > f->precision ? p_len : (size_t)f->precision;
	if (new_len - p_len)
	{
		tmp = ft_strnew(new_len);
		ft_memset(tmp, '0', new_len - p_len);
		ft_strncat(tmp, arg->param, p_len);
		arg->param = tmp;
	}
}
