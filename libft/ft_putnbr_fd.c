/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:16:42 by ewallner          #+#    #+#             */
/*   Updated: 2016/11/16 15:14:04 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int b;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		b = -n;
	}
	else
		b = n;
	if (b < 10)
		ft_putchar_fd((b + '0'), fd);
	else
	{
		ft_putnbr_fd(b / 10, fd);
		ft_putchar_fd(b % 10 + '0', fd);
	}
}
