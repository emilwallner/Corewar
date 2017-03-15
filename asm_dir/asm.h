/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:27:45 by mhaziza           #+#    #+#             */
/*   Updated: 2017/03/15 19:16:16 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>

typedef struct	s_read
{
	int	nb_char;
	int	nb_line;
}				t_read;

int				get_counts(char *file_name, t_read *tread);
int				get_asm(char *file_name, char *file, t_read *tread);
int				split_asm(char **asm_tab, char *file, int nb);

int				check_file(char **asm_tab, t_header *header);
#endif
