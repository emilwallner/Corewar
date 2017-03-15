/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:03:58 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/19 11:40:32 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if ((s1[0] || s2[0]) && s1[0] != s2[0])
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	if (s1[0] && s1[0] == s2[0])
		return (ft_strcmp(s1 + 1, s2 + 1));
	return (0);
}
