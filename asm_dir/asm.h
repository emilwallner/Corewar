/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:45 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/18 16:13:19 by mhaziza          ###   ########.fr       */
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
	t_op	op_tab[17];
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
int	get_id_by_name(char *name);

int				check_instructions(t_asm *tasm);
int				set_variables(t_instruction *line, char *str);
int				check_params(char *params, t_op top, t_asm *tasm);
int				check_valid_label(char *str);
int				count_label(t_asm *tasm);


int				check_register(char *params, t_op top, int p);
int				check_direct(char *params, t_op top, int p, t_asm *tasm);
int				check_indirect(char *params, t_op top, int p, t_asm *tasm);


int	set_label(t_asm *tasm, char *str, int iline);
int	existing_label(char *label, t_label *labels, int nb);
int	check_fill_label(char *label, t_label *labels, int nb, int index);
int	fill_label_tab(t_asm *tasm);
int	set_hexa(t_asm tasm, char *str, int nb_line);
void	set_op_tab(t_asm *tasm);
int	set_instruction(t_asm tasm, int fd, int nb_line);
#endif
