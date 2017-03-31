/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:15:58 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/16 15:16:07 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (*s && s != NULL)
	{
		dest[i++] = f((char)*s++);
	}
	dest[i] = '\0';
	return (dest);
}
