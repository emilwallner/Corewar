/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:35:59 by ewallner          #+#    #+#             */
/*   Updated: 2017/02/10 19:25:33 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_long(const char *s)
{
	int					i;
	int					isneg;
	long long			sum;

	sum = 0;
	i = 0;
	isneg = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || \
			s[i] == '\r' || s[i] == '\f')
		i++;
	if (s[i] == '-')
		isneg = -isneg;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		sum = sum * 10;
		sum = sum + (s[i] - '0');
		i++;
	}
	if (i > 19)
		return (2147483649);
	else
		return (sum * isneg);
}
