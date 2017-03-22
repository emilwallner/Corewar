/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewallner <ewallner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:20:20 by ewallner          #+#    #+#             */
/*   Updated: 2017/03/21 18:15:13 by nsabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../../libft/libft.h"
# include "op.h"
# include "curses.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_arena
{
	int		hex;
	int		color;
	int 	prevcolor;
}				t_arena;

typedef struct	s_player
{
	char name[PROG_NAME_LENGTH + 1];
	char comment[COMMENT_LENGTH + 1];
	char inst[CHAMP_MAX_SIZE + 1];
	int	len;
	int live;
	int	cursor_amount;
	int	index_start;
	char string[CHAMP_MAX_SIZE + 1];
	int	inst_len;
}				t_player;

typedef struct		s_cursor{
	struct s_cursor	*next;
	int				carry;
	int				counter;
	int				running;
	int				player;
	int				id;
	int				index;
	int				color;
	int				cycle;
	int 			cycle_end;
	int				comnd_len;
	int				command[6];
	int				reg[REG_NUMBER];
}					t_cursor;

typedef struct	s_env
{
	t_player	*player;
	t_cursor	*head;
	t_arena		a[MEM_SIZE];
	int 		cycle;
	int			lives;
	int			check;
	int			winner;
	int 		last_alive;
	int			cycles_to_die;
	char		**strings;
	char		arena[MEM_SIZE];
	int			player_amount;
	char		**files;
	t_op		op_tab[17];
}				t_env;

void 		ft_store_and_check_operation(t_env *e, t_cursor *cursor);
void 		ft_init_ncurses(void);
void		ft_update_cursor(t_env *e, t_cursor *cursor, int i);
void		ft_init_ncurses(void);
void		ft_cycle_break(t_env *e, t_cursor *cursor);
void		ft_adjust_cycle(t_env *e, t_cursor *cursor, int *end);
void		ft_declare_winner(t_env *e);
void		ft_new_cycle(t_env *e, int *end);
void		ft_print_function(int index, t_cursor *cursor, t_env *e);
void		ft_live(t_env *e, t_cursor *cursor);
void		ft_ld(char copied_code[30], t_env *e, t_cursor *cursor);
// void		ft_ld(t_env *e, t_cursor *cursor);
void		ft_st(t_env *e, t_cursor *cursor);
void		ft_add(t_env *e, t_cursor *cursor);
void		ft_sub(t_env *e, t_cursor *cursor);
void		ft_and(t_env *e, t_cursor *cursor);
void		ft_or(t_env *e, t_cursor *cursor);
void		ft_xor(t_env *e, t_cursor *cursor);
void		ft_zjmp(t_env *e, t_cursor *cursor);
void		ft_ldi(t_env *e, t_cursor *cursor);
void		ft_sti(t_env *e, t_cursor *cursor);
void		ft_fork(t_env *e, t_cursor *cursor);
void		ft_lld(t_env *e, t_cursor *cursor);
void		ft_lldi(t_env *e, t_cursor *cursor);
void		ft_lfork(t_env *e, t_cursor *cursor);
void		ft_aff(t_env *e, t_cursor *cursor);
void 		ft_move_cursors(t_env *e);
void		ft_print_cursor(t_env *e);
t_cursor	*ft_create_cursor(int i, t_env *e);
t_cursor	*ft_add_cursor_to_stack(t_cursor *stack, int i, t_env *e);
void		ft_init_cursor(t_env *e);
void		init_e(t_env *e, int ac, char **av);
void		ft_files_to_string(t_env *e);
void		ft_exit(t_env *e);
void		ft_print_strings(t_env *e, int ac);
void		ft_parsing(t_env *e, int ac);
void		ft_print_arena(t_env *e);
void 		ft_build_arena(t_env *e, int ac);
void		set_op_tab(t_env *e);
void		ft_check_args(t_env e, int opcode, int acb);
void		ft_debug(t_env e);


#endif
