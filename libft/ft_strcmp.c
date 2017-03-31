/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 09:02:20 by ewallner          #+#    #+#             */
/*   Updated: 2017/02/20 18:01:52 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if ((s1[0] || s2[0]) && s1[0] != s2[0])
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	if (s1[0] && s1[0] == s2[0])
		return (ft_strcmp(s1 + 1, s2 + 1));
	return (0);
}
