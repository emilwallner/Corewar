/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_walpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 18:20:18 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wctoa(wchar_t c)
{
	wchar_t	*str;

	if ((str = (wchar_t*)malloc(sizeof(c) + 1)) == NULL)
		return (NULL);
	str[0] = c ? c : '\0';
	str[1] = '\0';
	return (str);
}

wchar_t		*ft_set_wparam(wchar_t *param, t_flags *sflags, int new_len,
			int cpy_len)
{
	wchar_t	*final_p;
	int		p_len;
	int		i;

	i = -1;
	p_len = ft_get_nb_bytes(param, cpy_len);
	if ((final_p = (wchar_t*)malloc(sizeof(final_p) * new_len)) == NULL)
		return (NULL);
	while (++i < sflags->width - p_len && !sflags->minus && new_len > cpy_len)
		final_p[i] = sflags->zero ? '0' : ' ';
	if (cpy_len || (sflags->type == 'S' && (sflags->dot || sflags->width)))
		ft_wstrncpy(final_p + i, param, cpy_len);
	else
	{
		if (sflags->type == 'C')
			write(1, "\0", 1);
		return (param);
	}
	while (sflags->minus && new_len > cpy_len && i < sflags->width - cpy_len)
	{
		final_p[ft_wstrlen(param) + i] = ' ';
		i++;
	}
	return (final_p);
}

wchar_t		*ft_conv_walpha(wchar_t *param, t_flags *sflags)
{
	int		new_len;
	int		cpy_len;
	wchar_t	*final_p;
	int		p_len;

	if (!param)
		return (NULL);
	if (sflags->dot)
		cpy_len = ft_get_nb_wchar(param, sflags->precision);
	else
		cpy_len = ft_wbyteslen(param);
	p_len = ft_get_nb_bytes(param, cpy_len);
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;
	if (sflags->hashtag)
		return (NULL);
	if ((final_p = ft_set_wparam(param, sflags, new_len, cpy_len)) == NULL)
		return (NULL);
	if (sflags->type == 'C' && !p_len)
		sflags->emptyc = 1;
	return (final_p);
}
