/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:11:09 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/23 16:31:11 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (s)
	{
		if ((str = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (!s[i])
			return (ft_strsub(s, i, 0));
		j = ft_strlen(s) - 1;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		return (ft_strsub(s, i, j - i + 1));
	}
	return (NULL);
}
