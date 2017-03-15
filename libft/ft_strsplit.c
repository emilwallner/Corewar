/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:09:59 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/23 22:05:45 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_addneww(char const *s, char c, char **tab,
	unsigned int tab_size)
{
	unsigned int	i;
	unsigned int	neww_len;
	char			*neww;
	char			**tab_tmp;

	if (ft_strchr(s, c) != NULL)
		neww_len = ft_strchr(s, c) - s;
	else
		neww_len = ft_strlen(s);
	if ((neww = ft_strnew(neww_len)))
		neww = ft_strncpy(neww, s, neww_len);
	if ((tab_tmp = (char**)malloc(sizeof(char*) * (tab_size + 1))))
	{
		i = -1;
		while (++i < tab_size - 1)
			*(tab_tmp + i) = ft_strdup(*(tab + i));
		*(tab_tmp + tab_size - 1) = ft_strdup(neww);
		*(tab_tmp + tab_size) = 0;
		if (neww && neww[0])
			ft_strclr(neww);
		if (tab_size > 1 && tab && tab[0])
			ft_strdel(tab);
	}
	return (tab_tmp);
}

static char	**ft_stotab(char const *s, char c, char **tab,
	unsigned int tab_size)
{
	if (s[0] && s[0] == c)
		return (ft_stotab(s + 1, c, tab, tab_size));
	if (s[0] && s[0] != c && ft_strchr(s, c))
	{
		return (ft_stotab(ft_strchr(s, c), c,
		ft_addneww(s, c, tab, tab_size + 1), tab_size + 1));
	}
	if (s[0] && s[0] != c && ft_strchr(s, c) == NULL)
		return (ft_addneww(s, c, tab, tab_size + 1));
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	tab_size;
	char			**tab;
	int				i;

	tab_size = 0;
	if (!s || !c)
		return (NULL);
	if ((tab = (char**)malloc(sizeof(char*))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (!s[0] || i == (int)ft_strlen(s))
	{
		tab[0] = 0;
		return (tab);
	}
	tab = ft_stotab(s, c, tab, tab_size);
	return (tab);
}
