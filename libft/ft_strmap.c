/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:16:38 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/23 16:25:24 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	if (s)
	{
		i = -1;
		dest = ft_strdup((char*)s);
		if (!dest)
			return (NULL);
		while (s[++i])
			dest[i] = f(dest[i]);
		return (dest);
	}
	return (NULL);
}
