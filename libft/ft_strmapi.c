/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:00:33 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/23 16:29:15 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			dest[i] = f(i, dest[i]);
		return (dest);
	}
	return (NULL);
}
