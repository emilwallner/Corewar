/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:56:53 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/31 11:49:49 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** In this .c file, we gonna parse the data + check for errors
** We to get:
** 		- COREWAR_EXEC_MAGIC
**		- Name of the .cor
**		- Comments
**		- Instructions
*/

void	ft_add_player_name(t_env *e, int k)
{
	char	*dest;
	char	*src;
	int		i;

	src = e->player[k].string;
	dest = e->player[k].name;
	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		dest[i] = src[i + 4];
		i++;
	}
	while (i <= PROG_NAME_LENGTH)
		dest[i++] = '\0';
	dest[PROG_NAME_LENGTH] = '\0';
}

void	ft_add_player_comment(t_env *e, int k)
{
	char	*dest;
	char	*src;
	int		i;

	src = e->player[k].string;
	dest = e->player[k].comment;
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		dest[i] = src[i + PROG_NAME_LENGTH + 12];
		i++;
	}
	while (i <= COMMENT_LENGTH)
		dest[i++] = '\0';
	dest[COMMENT_LENGTH] = '\0';
}
