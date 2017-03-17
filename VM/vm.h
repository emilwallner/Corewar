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

typedef struct	s_label
{
	char	*label;
	int		index;
}				t_label;

typedef struct	s_asm
{
	char	**asm_tab;
	t_label	*labels;
	int		nb_labels;
}				t_asm;

typedef struct	s_instruction
{
	char	*name;
	char	*params;
	char	*label;
}				t_instruction;

// static void	counts_char_line(char *buff, t_read *tread);
int			get_counts(char *file_name, t_read *tread);
int			get_asm(char *file_name, char *file, t_read *tread);
int			split_asm(char **asm_tab, char *file, int nb);


#endif
