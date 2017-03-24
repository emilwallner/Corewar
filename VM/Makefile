# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 15:57:23 by mhaziza           #+#    #+#              #
#    Updated: 2017/03/24 15:34:56 by nsabbah          ###   ########.fr        #
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
				ft_ld.c \
				main_test.c \
				tests_ft_ld.c \


GREEN		= \033[32m
RED			= \033[31m
DEFAULT		= \033[37m
CYAN    	= \x1b[36m

OBJS	=	$(SRCS:.c=.o)
VPATH	=	srcs/:funcs/:funcs_tests/:

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
