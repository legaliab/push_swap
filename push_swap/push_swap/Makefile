# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 18:03:46 by alabdull          #+#    #+#              #
#    Updated: 2023/05/03 23:22:51 by alabdull         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	push_swap.c parsing1.c parsing2.c create_stack.c sort.c error.c \
		push.c rotate.c rrotate.c swap.c utils.c utils1.c utils2.c utils3.c \

OBJ = $(SRC:.c=.o)

CC = gcc -g3 
# -fsanitize=address

OBJ = $(SRC:.c=.o)

NAME = push_swap

LIB = Libft/libft.a

PRINTF = Libft/ft_printf/libftprintf.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -sC ./Libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) $(PRINTF) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -sC ./Libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./Libft

re: fclean all

.PHONY: all clean fclean re
