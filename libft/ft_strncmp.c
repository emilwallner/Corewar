/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:24:20 by mhaziza           #+#    #+#             */
/*   Updated: 2016/11/19 11:45:22 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n && (s1[0] || s2[0]) && s1[0] != s2[0])
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	if (n && s1[0] && s1[0] == s2[0])
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	return (0);
}
