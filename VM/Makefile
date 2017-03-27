# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 15:57:23 by mhaziza           #+#    #+#              #
#    Updated: 2017/03/27 19:30:04 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COREWAR = 	corewar
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -g
RM		=   rm -f
MKDIR	= 	mkdir -p
LIBFT	=	 -L../libft -lft -lcurses
LIBFT_PATH	= ../libft
INC_COREWAR = ./srcs/vm.h
SRCS	=		main_vm.c 	\
				files_to_strings.c \
				init_e.c \
				error.c \
				parsing.c \
				ft_print_arena.c \
				ft_build_arena.c \
				op.c \
				functions.c \
				ft_check_args.c \
				init_cursors.c \
				move_cursors.c \
				add_cycle.c \
				adjust_cycles.c \
				init_ncurses.c \
				declare_winner.c \
				ft_cp_int.c \
				ft_fork.c \
				ft_lfork.c \
				ft_live.c \
				ft_add.c \
				ft_and.c \
				ft_or.c \
				ft_sub.c \
				ft_zjmp.c \
				ft_aff.c \
				ft_lld.c \
				ft_ldi.c \
				ft_ld.c \
				ft_st.c \
				ft_sti.c \
				main_test.c \
				tests_ft_ld.c \
				tests_ft_add.c \
				tests_ft_or.c \
				tests_ft_and.c \
				tests_ft_sub.c \
				tests_ft_ldi.c \
				tests_ft_lld.c \
				tests_ft_st.c \
				tests_ft_sti.c \
				ft_funcs_tools.c \

GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m
CYAN    	= \x1b[36m

OBJS	=	$(SRCS:.c=.o)
VPATH	=	srcs/:funcs/:funcs_tests/:funcs/funcs_tests

all: libft $(COREWAR)
libft:
	@make -C $(LIBFT_PATH)

# Executables
$(COREWAR): $(OBJS)
	@$(CC) -o $@ $(CFLAGS) $^ -I $(INC_COREWAR) $(LIBFT)
	@echo "$(GREEN)Success"

# Object files
$(OBJS): $(SRCS)
	@$(CC) -c $^ $(CFALGS) -I $(INC_COREWAR)

# Cleaning rules
clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@echo "$(GREEN)Clean$(DEFAULT)"

fclean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)
	@rm -rf $(COREWAR)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)Program removed$(DEFAULT)"

re: fclean all
.PHONY: clean fclean re libft
