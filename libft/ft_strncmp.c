/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:10:22 by ewallner          #+#    #+#             */
/*   Updated: 2017/02/17 20:42:06 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n && (s1[0] || s2[0]) && s1[0] != s2[0])
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	if (n && s1[0] && s1[0] == s2[0])
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	return (0);
}
