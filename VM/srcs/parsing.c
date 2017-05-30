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

void	ft_check_coding_byte(t_env *e, int k)
{
	char	*str;
	int		number;

	str = e->player[k].string;
	number = ((MM(str[0]) << 24) | (MM(str[1]) << 16) | (MM(str[2]) << 8) |
	MM(str[3]));
	if (number != COREWAR_EXEC_MAGIC)
		ft_exit(e, 4);
}

void	ft_check_label_name(t_env *e, int k)
{
	int		i;
	char	*name;

	i = -1;
	name = e->player[k].name;
	while (name[++i])
		if (!(ft_strchr(CMD_CHARS, name[i])))
			ft_exit(e, 5);
}

void	ft_check_label_comment(t_env *e, int k)
{
	int		i;
	char	*comment;

	i = -1;
	comment = e->player[k].comment;
	while (comment[++i])
		if (!(ft_strchr(CMD_CHARS, comment[i])))
			ft_exit(e, 10);
}

void	ft_check_all(t_env *e, int i)
{
	ft_check_coding_byte(e, i);
	ft_add_player_name(e, i);
	ft_add_player_comment(e, i);
	ft_check_label_name(e, i);
	ft_check_label_comment(e, i);
}

void	ft_parsing(t_env *e)
{
	int		i;
	int		k;
	char	*str;
	char	*inst;

	i = -1;
	while (++i < e->player_amount)
	{
		str = e->player[i].string;
		ft_check_all(e, i);
		k = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
		inst = e->player[i].inst;
		e->player[i].inst_len = k;
		while (k < e->player[i].len)
		{
			*inst = str[k];
			k++;
			inst++;
		}
		e->player[i].inst_len = k - e->player[i].inst_len;
		if (e->player[i].inst_len > CHAMP_MAX_SIZE)
			ft_exit(e, 6);
	}
}
