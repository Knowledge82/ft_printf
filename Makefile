# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 14:29:48 by vdarsuye          #+#    #+#              #
#    Updated: 2024/08/21 15:58:32 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Lib name

NAME = libftprintf.a


#Colors

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m


# Flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror


# Vars and Files

SRC = ft_printf.c print_char.c print_str.c print_int.c \
	print_unsigned.c print_hexa.c print_pointer.c

OBJ = $(SRC:.c=.o)


# Rules

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Library $(NAME) created.$(RESET)"

%.o : %.c Makefile ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	@echo "$(RED)Object files removed.$(RESET)"

fclean : clean
	rm -f $(NAME)
	@echo "$(RED)Library $(NAME) removed.$(RESET)"

re : fclean all

.PHONY: all clean fclean re
