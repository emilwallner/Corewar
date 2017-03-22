/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:56:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/19 19:11:30 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


/*
**
** In this .c file, we gonna parse the data + check for errors
** We to get:
** 		- COREWAR_EXEC_MAGIC
**		- Name of the .cor
**		- Comments
**		- Instructions
**
*/

void ft_parsing(t_env *e, int ac)
{
	// int	error;
	int		i;
	int		k;
	int		hex;
	char	*str;
	char	*inst;

	i = 1;
	while (i < ac)
	{

	k = PROG_NAME_LENGTH + COMMENT_LENGTH;
	str = e->player[i].string;
	inst = e->player[i].inst;
	while (!(str[k]))
		k++;
	e->player[i].inst_len = k;
    while(k < e->player[i].len)
	{
		hex = 0xFF & (str[k]);
		*inst = str[k];
		k++;
		inst++;
	}
	e->player[i].inst_len = k - e->player[i].inst_len;
	i++;
	}
}
