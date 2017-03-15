/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:15:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/19 19:01:32 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wputstr(const wchar_t *s)
{
	int	i;
	int	total_length;

	i = -1;
	total_length = 0;
	if (!s)
		return (ft_putstr("(null)"));
	else
	{
		while (++i < (int)ft_wstrlen(s))
			total_length += ft_wputchar(s[i]);
		return (total_length);
	}
}
