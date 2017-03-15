/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:45:32 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 19:32:34 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_print_str(char *str, int *tl)
{
	char	*next;

	if ((next = ft_strchr(str, '%')) == NULL)
		*tl += ft_wputstr((int*)str);
	else if (next)
	{
		*tl += next - str;
		write(1, str, next - str);
	}
	return (next);
}

char	*ft_ifpercent(char *str, t_flags *sflags, int *tl)
{
	int		i;
	char	*param;

	i = 0;
	sflags->type = '%';
	while (i < sflags->flags_len && str[i])
	{
		if (ft_strchr("+-. ", str[i]))
			i++;
		else if (ft_isdigit(str[i]) && (sflags->width || sflags->precision))
			i++;
		else
		{
			param = ft_conv_alpha(ft_ctoa(str[i]), sflags);
			*tl += ft_putstr(param);
			if (str + i + 2)
				return (str + i + 2);
			else
				return (NULL);
		}
	}
	return (NULL);
}

void	ft_adjust_size(t_flags *sflags, char *param, int *tl)
{
	if (sflags->minus)
		write(1, "\0", 1);
	if (sflags->width)
		*tl += ft_putstr(param) + 1;
	else
		*tl += 1;
	if (!sflags->minus)
		write(1, "\0", 1);
}

char	*ft_print_params(char *str, t_flags *sflags, va_list ap, int *tl)
{
	char	type;
	char	*param;

	type = sflags->type;
	if ((type == '%' && sflags->percent == -1) || sflags->is_invalid)
		return (ft_ifpercent(str, sflags, tl));
	else if (type == '%' && !sflags->percent)
	{
		sflags->space = 0;
		param = ft_conv_alpha(ft_ctoa(type), sflags);
	}
	else
		param = ft_cast_arg(sflags, ap, tl);
	if ((!ft_strlen(param) || sflags->emptyc) && ft_strchr("c", type))
	{
		ft_adjust_size(sflags, param, tl);
	}
	else if (param && !ft_strchr("SC", type))
		*tl += ft_putstr(param);
	return (str + sflags->flags_len + 1);
}
