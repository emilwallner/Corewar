/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/26 10:43:29 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ctoa(int c)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(c) + 1)) == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char		*ft_set_param(char *param, t_flags *sflags, int new_len,
			int cpy_len)
{
	char	*final_p;
	int		i;
	int		p_len;

	if ((final_p = ft_strnew((size_t)new_len)) == NULL)
		return (NULL);
	i = -1;
	p_len = ft_strlen(param);
	while (++i < sflags->width - cpy_len && !sflags->minus && new_len > cpy_len)
		final_p[i] = sflags->zero ? '0' : ' ';
	ft_strncpy(final_p + i, param, cpy_len);
	while (sflags->minus && new_len > cpy_len && i < sflags->width - cpy_len)
	{
		final_p[cpy_len + i] = ' ';
		i++;
	}
	if (sflags->type == 'c' && !p_len && new_len > 1)
	{
		if (sflags->width > 1)
			sflags->emptyc = 1;
		return (final_p + 1);
	}
	return (final_p);
}

char		*ft_conv_alpha(char *param, t_flags *sflags)
{
	int		new_len;
	int		cpy_len;
	int		p_len;
	char	*final_p;

	if (!param && !sflags->width)
	{
		final_p = ft_strnew(6);
		final_p = "(null)";
		return (final_p);
	}
	p_len = ft_strlen(param);
	cpy_len = sflags->dot && sflags->precision < p_len && sflags->type != '%' ?
	sflags->precision : p_len;
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;
	if (sflags->type != '%' && (sflags->hashtag))
		return (NULL);
	return (ft_set_param(param, sflags, new_len, cpy_len));
}
