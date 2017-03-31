/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:45:21 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/30 19:00:25 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_error_msg[11] =
{
	"op.h -> forbidden characters ('\\n', ' ', ...) in #define.\n",
	"op.h -> COREWAR_EXEC_MAGIC > 0xffffffff\n",
	"wrong file extension.\n",
	"Error in label's name.\n",
	"Error in champion's name.\n",
	"Error in file's comment.\n",
	"Error in comment.\n",
	"Error : number of parameter invalid\n",
	"Error : registry parameter invalid\n",
	"Error : direct parameter invalid\n",
	"Error : indirect parameter invalid\n"
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
