# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 15:57:23 by mhaziza           #+#    #+#              #
#    Updated: 2017/03/20 14:42:05 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	asm
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I. -fsanitize=address
RM		=   rm -f
LIBFT	=	 -L../libft -lft
SRCS	=	asm.c \
			op.c \
			get_asm.c \
			get_asm_master.c \
			check_file.c  \
			labels_utils.c \
			check_instruction.c \
			check_label.c \
			check_params.c \
			check_params_utils.c \
			set_hexa.c \
			set_hexa_instruction.c \
			set_hexa_params.c \
			set_hexa_labels.c \

OBJS	=   $(SRCS:.c=.o)

LIBFT_PATH	= ../libft

all:	$(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAG) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re:		fclean all

.PHONY:		all clean fclean re
