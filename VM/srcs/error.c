/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:16:11 by ewallner          #+#    #+#             */
/*   Updated: 2017/04/26 17:44:00 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_clean_head(t_cursor *head)
{
	t_cursor *temp;

	while (head)
	{
		if (head->next)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		if (head->counter)
		{
			free(head);
			head = NULL;
		}
	}
}

void	ft_error_usage(void)
{
	ft_putstr_fd(" Usage:\n \
	Example: ./corewar -visual -n -1 ./Players/helltrain.cor\n \
	GUI: ./corewar -visual [Players]\n \
	Default Player Numbers: 1, 2, 3, 4...\n \
	Change Player Number: -n -1 ./Players/helltrain.cor\n \
	Dump: ./corewar -dump 300 [Players](prints the memory after 300 cycles)\n \
	Game on! 👾 🤖 🔫 \n", 2);
	exit(1);
}

void	ft_error_msg(int i)
{
	if (i == 1)
		ft_putstr_fd("\x1b[31m[Failed to open]\x1b[0m ", 2);
	else if (i == 2)
		ft_putstr_fd("\x1b[31m[Failed to read file]\x1b[0m ", 2);
	else if (i == 3)
		ft_putstr_fd("\x1b[31m[Failed to close file]\x1b[0m ", 2);
	else if (i == 4)
		ft_putstr_fd("\x1b[31m[Wrong Corewar Exec Magic]\x1b[0m ", 2);
	else if (i == 5)
		ft_putstr_fd("\x1b[31m[Incorrect Name Chars]\x1b[0m ", 2);
	else if (i == 6)
		ft_putstr_fd("\x1b[31m[Player size too big]\x1b[0m ", 2);
	else if (i == 7)
		ft_putstr_fd("\x1b[31m[Wrong int value]\x1b[0m ", 2);
	else if (i == 8)
		ft_putstr_fd("\x1b[31m[Too many players]\x1b[0m ", 2);
	else if (i == 9)
		ft_putstr_fd("\x1b[31m[Duplicate player number]\x1b[0m ", 2);
	else if (i == 10)
		ft_putstr_fd("\x1b[31m[Incorrect comment chars]\x1b[0m ", 2);
	else
		ft_putstr_fd("\x1b[31m[ERROR]\x1b[0m ", 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	ft_exit(t_env *e, int i)
{
	if (e->head)
		ft_clean_head(e->head);
	if (i > 0)
		ft_error_msg(i);
}
