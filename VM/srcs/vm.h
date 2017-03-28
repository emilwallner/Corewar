/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabbah <nsabbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 13:56:56 by nsabbah           #+#    #+#             */
/*   Updated: 2017/03/28 17:26:30 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../../libft/libft.h"
# include "op.h"
# include "curses.h"
# include <stdio.h>
# include <limits.h>
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define MODA(x)	(x % MEM_SIZE < 0 ? x % MEM_SIZE + MEM_SIZE : x % MEM_SIZE)
# define MODX(x)	(x % IDX_MOD)
# define MM(x)		(x & 0xFF)
# define ZMASK(x)	(x & 0xFF)
# define ABS(value)  (value > 0 ? value : -value)
# define RRR 0b01010100
# define RIR 0b01110100
# define RDR 0b01100100
# define IRR 0b11010100
# define IIR 0b11110100
# define IDR 0b11100100
# define DRR 0b10010100
# define DIR 0b10110100
# define DDR 0b10100100

typedef struct s_var
{
	int			r1;
	int			r2;
	int			r3;
	int			ind;
	char		acb;
}				t_var;

typedef struct s_arena
{
	char 	hex;
	int		color;
	int 	prevcolor;
	int 	occupied;
	int 	new_color_count;
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
	struct s_cursor	*prev;
	int				carry;
	int				counter;
	int				running;
	int				player;
	int				index;
	int				color;
	int				cycle;
	int				reg[REG_NUMBER];
}					t_cursor;

typedef struct	s_env
{
	t_player	player[MAX_PLAYERS];
	t_cursor	*head;
	t_arena		a[MEM_SIZE];
	int 		cursors;
	int 		cycle;
	int 		tot_cycle;
	int			lives;
	int			check;
	int 		bonus;
	char		winner;
	int 		last_alive;
	int			cycles_to_die;
	char		arena[MEM_SIZE];
	int			player_amount;
	char		**files;
	t_op		op_tab[17];
}				t_env;


void		ft_fork_both(t_env *e, t_cursor *cursor, int lfork);
void		ft_update_cursor(t_env *e, t_cursor *cursor, int i);
void		ft_add_cycle(t_env *e, t_cursor *cursor);
void 		ft_init_ncurses(void);
void		ft_update_cursor(t_env *e, t_cursor *cursor, int i);
void		ft_init_ncurses(void);
void 		ft_cycle_end_and_execute(t_env *e, t_cursor *cursor);
void 		ft_adjust_cycle_macro(t_env *e, t_cursor *cursor, int *end);
void		ft_declare_winner(t_env *e);
void		ft_new_cycle(t_env *e, int *end);
void		ft_print_function(int index, t_cursor *cursor, t_env *e);
void		ft_live(t_env *e, t_cursor *cursor);
// void		ft_ld(char copied_code[30], t_env *e, t_cursor *cursor);
void		ft_ld(t_env *e, t_cursor *cursor);
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
void		ft_init_cursor(t_env *e);
void		init_e(t_env *e, int ac, char **av);
void		ft_files_to_string(t_env *e);
void		ft_exit(t_env *e, int i);
void		ft_print_strings(t_env *e, int ac);
void		ft_parsing(t_env *e, int ac);
void		ft_print_arena(t_env *e);
void 		ft_build_arena(t_env *e, int ac);
void		set_op_tab(t_env *e);
int			ft_check_args(t_env e, t_cursor cursor);
void		ft_debug(t_env e);
int			ft_cp_int(int int_start, t_env e);
int			ft_is_reg(int r1, int r2, int r3);
int			get_dir(t_env *e, t_cursor *cursor, int i, int bytes);
int			get_ind(t_env *e, t_cursor *cursor, int i);
int			get_reg(t_env *e, t_cursor *cursor, int i);
int			get_bytes(t_env *e, t_cursor *cursor, int r);
int			is_reg_valid(int i);
int			check_register_ldi(t_env *e, t_cursor *cursor, char acb);


// Testing section
void	ft_tests_ld(t_env e, t_cursor *cursor);
void	ft_tests_ld2(t_env e, t_cursor *cursor);
void	ft_tests_lld(t_env e, t_cursor *cursor);
void	ft_tests_lld2(t_env e, t_cursor *cursor);
void	ft_tests_ldi(t_env e, t_cursor *cursor);
void	ft_tests_ldi2(t_env e, t_cursor *cursor);
void	ft_tests_add(t_env e, t_cursor *cursor);
void	ft_tests_add2(t_env e, t_cursor *cursor);
void	ft_tests_sub(t_env e, t_cursor *cursor);
void	ft_tests_sub2(t_env e, t_cursor *cursor);
void	ft_debug_sti(t_env e, t_cursor *cursor);
void	ft_debug_ldi(t_env e, t_cursor *cursor);
void	ft_tests_and(t_env e, t_cursor *cursor);
void	ft_tests_and1(t_env e, t_cursor *cursor);
void	ft_tests_and2(t_env e, t_cursor *cursor);
void	ft_tests_and3(t_env e, t_cursor *cursor);
void	ft_tests_and4(t_env e, t_cursor *cursor);
void	ft_tests_and5(t_env e, t_cursor *cursor);
void	ft_tests_and6(t_env e, t_cursor *cursor);
void	ft_tests_and7(t_env e, t_cursor *cursor);
void	ft_tests_and8(t_env e, t_cursor *cursor);
void	ft_debug_sti(t_env e, t_cursor *cursor);
void	ft_tests_or(t_env e, t_cursor *cursor);
void	ft_tests_or1(t_env e, t_cursor *cursor);
void	ft_tests_or2(t_env e, t_cursor *cursor);
void	ft_tests_or3(t_env e, t_cursor *cursor);
void	ft_tests_or4(t_env e, t_cursor *cursor);
void	ft_tests_or5(t_env e, t_cursor *cursor);
void	ft_tests_or6(t_env e, t_cursor *cursor);
void	ft_tests_or7(t_env e, t_cursor *cursor);
void	ft_tests_or8(t_env e, t_cursor *cursor);
void	ft_tests_xor(t_env e, t_cursor *cursor);
void	ft_tests_xor1(t_env e, t_cursor *cursor);
void	ft_tests_xor2(t_env e, t_cursor *cursor);
void	ft_tests_xor3(t_env e, t_cursor *cursor);
void	ft_tests_xor4(t_env e, t_cursor *cursor);
void	ft_tests_xor5(t_env e, t_cursor *cursor);
void	ft_tests_xor6(t_env e, t_cursor *cursor);
void	ft_tests_xor7(t_env e, t_cursor *cursor);
void	ft_tests_xor8(t_env e, t_cursor *cursor);
#endif
