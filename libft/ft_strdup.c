/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:36:41 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/15 17:31:29 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = ft_strnew(ft_strlen(s));
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy(dest, s);
	return (dest);
}
