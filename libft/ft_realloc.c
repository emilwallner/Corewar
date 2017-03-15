/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:41:05 by mhaziza           #+#    #+#             */
/*   Updated: 2017/02/17 14:55:23 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc(char **tab, char *neww)
{
	unsigned int	i;
	unsigned int	tab_size;
	char			**tab_tmp;

	tab_size = 0;
	while (tab && tab[tab_size])
		tab_size++;
	if (!(tab_tmp = (char**)malloc(sizeof(char*) * (tab_size + 2))))
		return (NULL);
	i = 0;
	while (i < tab_size)
	{
		tab_tmp[i] = tab[i];
		i++;
	}
	tab_tmp[i] = ft_strdup(neww);
	tab_tmp[i + 1] = 0;
	free(tab);
	return (tab_tmp);
}
