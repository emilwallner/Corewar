/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:20:20 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/17 14:20:23 by ewallner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>
# include <limits.h>

typedef struct	s_read
{
	int	nb_char;
	int	nb_line;
}				t_read;

static int	free_and_return(char *file, char **asm_tab, int free_tab, int ret);
static void	counts_char_line(char *buff, t_read *tread);
int			get_asm(char *file_name, char *file, t_read *tread);
int			split_asm(char **asm_tab, char *file, int nb);


#endif
