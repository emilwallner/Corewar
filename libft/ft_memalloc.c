/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:14:11 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/07 22:54:42 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*s;

	s = malloc(size);
	if (s == NULL)
		return (NULL);
	else
		ft_bzero(s, size);
	return (s);
}
