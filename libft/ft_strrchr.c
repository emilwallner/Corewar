/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:28:03 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/19 10:35:34 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int len;
	int pos;

	i = -1;
	len = ft_strlen((char*)s);
	pos = -1;
	if (!c)
		return ((char*)s + len);
	while (++i < len)
		if (s[i] == (unsigned char)c)
			pos = i;
	if (pos >= 0)
		return ((char*)s + pos);
	return (NULL);
}
