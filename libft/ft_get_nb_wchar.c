/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:31:09 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/26 10:50:09 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_get_nb_wchar(wchar_t *src, int n)
{
	unsigned int	i;
	unsigned int	m;
	unsigned int	ibytes;

	i = 0;
	ibytes = 0;
	m = (unsigned int)n;
	while (ibytes < m && src[i])
	{
		if (src[i] <= ft_atoi_base("7F", 16) && ibytes + 1 <= m)
			ibytes += 1;
		else if (src[i] <= ft_atoi_base("7FF", 16) && ibytes + 2 <= m)
			ibytes += 2;
		else if (src[i] <= ft_atoi_base("FFFF", 16) && ibytes + 3 <= m)
			ibytes += 3;
		else if (src[i] <= ft_atoi_base("10FFFF", 16) && ibytes + 4 <= m)
			ibytes += 4;
		else
			return (i);
		i++;
	}
	return (i);
}
