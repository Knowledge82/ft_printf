# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 14:29:48 by vdarsuye          #+#    #+#              #
#    Updated: 2024/08/21 14:52:46 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Lib name

NAME = libftprintf.a


# Flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror


# Files

SRC =   ft_printf.c print_char.c print_str.c print_int.c /
	print_unsigned.c print_hexa.c print_pointer.c

OBJ = $(SRC: .c=.o)

# Rules


all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created."

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	@echo "Object files removed."

fclean : clean
	rm -f $(NAME)
	@echo "Library $(NAME) removed."

re : fclean all

.PHONY: all clean fclean re
