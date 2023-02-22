# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alabdull <alabdull@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 18:03:46 by alabdull          #+#    #+#              #
#    Updated: 2023/02/20 18:06:48 by alabdull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = utils.c\

OBJ = $(SRC:.c=.o)

CC = gcc -g3 -fsanitize=address

NAME = push_swap

LIB = ./Libft/libft.a

PRINTF = ./Libft/ft_printf/libftprintf.a

GNL = ./Libft/get_next_line/get_next_line.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC ./Libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(PRINTF) $(GNL) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -sC ./Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./Libft

re: fclean all

.PHONY: all clean fclean re