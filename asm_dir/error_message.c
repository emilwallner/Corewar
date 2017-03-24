/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:45:21 by tlenglin          #+#    #+#             */
/*   Updated: 2017/03/24 15:34:32 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*g_error_msg[3]=
{
	"op.h -> forbidden characters ('\\n', ' ', ...) in #define.\n",
	"op.h -> COREWAR_EXEC_MAGIC > 0xffffffff\n",
	"wrong file extension\n"
};

int	error_header(int id)
{
	ft_putstr_fd(g_error_msg[id], 2);
	return (0);
}
