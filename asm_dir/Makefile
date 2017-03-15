# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/15 15:57:23 by mhaziza           #+#    #+#              #
#    Updated: 2017/03/15 19:15:54 by mhaziza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	asm
CC		=   gcc
CFLAGS	= 	-Wall -Wextra -Werror -I. -fsanitize=address
RM		=   rm -f
LIBFT	=	 -L../libft -lft
SRCS	=	asm.c \
			get_asm_utils.c \
			op.c \
			file_check.c  \

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
