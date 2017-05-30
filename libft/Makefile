# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewallner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 16:30:18 by ewallner          #+#    #+#              #
#    Updated: 2017/02/10 16:51:52 by ewallner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = libft.h
HEADPRINTF = ft_print.h
FLAG =  -Werror -Wextra -Wall
OPTION = -c -include $(HEAD) -include $(HEADPRINTF)
SRC = ft_putchar.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr.c ft_strlen.c \
	  ft_putnbr_fd.c ft_putnbr.c ft_putendl_fd.c ft_putendl.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_tolower.c ft_toupper.c \
	  ft_atoi.c ft_itoa.c \
	  ft_memset.c ft_bzero.c ft_memalloc.c ft_strnew.c ft_memdel.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strdup.c \
	  ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strdel.c ft_strstr.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strlcat.c \
	  get_next_line.c ft_count_words.c ft_strstrlen.c ft_base.c ft_atoi_base.c \
	  ft_converttype.c ft_error_handle.c ft_parser.c ft_printwchar.c \
	  ft_chars.c ft_strings.c ft_wstrings.c main.c ft_atoi_calc.c \
	  ft_extra_atoi_base.c ft_atoi_long.c get_next_line_dr.c ft_atoli.c \

OBJ = $(SRC:%.c=%.o)

GREEN		= \033[32m
RED			= \033[31m
DEFAULT	= \033[37m
CYAN    = \x1b[36m

$(NAME):
	@gcc $(FLAG) $(OPTION) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)Libft created.$(DEFAULT)"

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)Libft destroyed.$(DEFAULT)"

re: fclean all
