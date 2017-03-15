/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:15:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/19 12:34:49 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr(char const *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (0);
	}
	else
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
}
