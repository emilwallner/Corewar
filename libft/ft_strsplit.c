/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:47:45 by ewallner          #+#    #+#             */
/*   Updated: 2016/12/13 17:07:05 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_cntwrd(char const *s, char c)
{
	unsigned int	i;
	int				w;
	int				m;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		m = 0;
		while (s[i] != c)
		{
			m = 1;
			if (s[i] == '\0')
				return (w + 1);
			i++;
		}
		if (m == 1)
			w++;
		i++;
	}
	return (w);
}

static int	ft_untilc(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	f;
	int				w;
	char			**list;

	if (s == NULL)
		return (NULL);
	if (!(list = (char**)malloc(sizeof(*list) * ft_cntwrd(s, c) + 1)))
		return (NULL);
	f = 0;
	w = -1;
	while (++w < ft_cntwrd(s, c))
	{
		i = 0;
		while (s[i + f] == c)
			f++;
		i = ft_untilc(&s[f], c);
		if (!(list[w] = ft_strnew(i)))
			return (NULL);
		if (i > 0)
			list[w] = ft_strncpy(list[w], &s[f], i);
		f = f + i;
	}
	list[w] = NULL;
	return (list);
}
