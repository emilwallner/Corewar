/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 10:14:03 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/17 15:20:11 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (s)
	{
		if ((str = ft_strnew(len)) == NULL)
			return (NULL);
		i = -1;
		while (++i < len)
			str[i] = s[start + i];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
