/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:45:21 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/31 15:42:02 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_error_msg[11] =
{
	"\x1b[31mop.h -> forbidden characters ('\\n', ' ', ...) in #define.\x1b[0m\n",
	"\x1b[31mop.h -> COREWAR_EXEC_MAGIC > 0xffffffff\x1b[0m\n",
	"\x1b[31mwrong file extension.\x1b[0m\n",
	"\x1b[31mError in label's name.\x1b[0m\n",
	"\x1b[31mError in champion's name.\x1b[0m\n",
	"\x1b[31mError in file's comment.\x1b[0m\n",
	"\x1b[31mError in comment.\x1b[0m\n",
	"\x1b[31mError : number of parameter invalid\x1b[0m\n",
	"\x1b[31mError : registry parameter invalid\x1b[0m\n",
	"\x1b[31mError : direct parameter invalid\x1b[0m\n",
	"\x1b[31mError : indirect parameter invalid\x1b[0m\n"
};

int	error_header(int id)
{
	ft_putstr_fd(g_error_msg[id], 2);
	return (0);
}

int	eol(int id)
{
	ft_putstr_fd(g_error_msg[id], 2);
	return (0);
}

int	eoll(int id, int line)
{
	ft_putstr_fd("Line ", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(g_error_msg[id], 2);
	return (0);
}
