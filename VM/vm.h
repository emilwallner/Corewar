/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:20:20 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/18 15:20:47 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>
# include <limits.h>

typedef struct	s_player
{
	char name[PROG_NAME_LENGTH + 1];
	char comment[COMMENT_LENGTH + 1];
	char instructions[CHAMP_MAX_SIZE - PROG_NAME_LENGTH - COMMENT_LENGTH];
	int	len;
	char string[CHAMP_MAX_SIZE + 1];
}				t_player;

typedef struct	s_env
{
	t_player *player;
	char **strings;
	int		player_amount;
	char **files;
}				t_env;

void 		init_e(t_env *e, int ac, char **av);
void  	ft_files_to_string(t_env *e);
void 		ft_exit(t_env *e);
void ft_print_strings(t_env *e, int ac);

#endif
