/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:45 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/16 17:41:23 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>
# include <limits.h>

# define MIN(a,b) (a < b ? a : b)

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

int				get_counts(char *file_name, t_read *tread);
int				get_asm(char *file_name, char *file, t_read *tread);
int				split_asm(char **asm_tab, char *file, int nb);

int				check_file(char **asm_tab, t_header *header);
int	check_instructions(t_asm *tasm);
int		check_params(char *params, t_op top, t_asm *tasm);
int	count_label(t_asm *tasm);
// int	check_file_instructions(char **asm_tab);

#endif
