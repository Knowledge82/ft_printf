# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 14:29:48 by vdarsuye          #+#    #+#              #
#    Updated: 2025/11/24 21:53:55 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

#Colors
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
NEON_GREEN = \033[92m

#Lib name
NAME = libftprintf.a

#Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

#Dirs
LIBFT_DIR = ./libft

#Libs
LIBFT = $(LIBFT_DIR)/libft.a

#Srcs files - Common
SRCS_COMMON = print_char.c \
			  print_str.c \
			  print_int.c \
			  print_unsigned.c \
			  print_hexa.c \
			  print_pointer.c

#Srcs files - Mandatory
SRCS_MANDATORY = ft_printf.c

#Srcs files - Bonus
SRCS_BONUS = ft_printf_bonus.c \
			 flags_bonus.c \
			 print_char_bonus.c \
			 print_str_bonus.c \
			 print_int_bonus.c \
			 print_int_format_out.c \
			 print_unsigned_bonus.c \
			 print_hexa_bonus.c \
			 print_hexa_format_out.c \
			 print_pointer_bonus.c

#Objs files
OBJS_COMMON = $(SRCS_COMMON:.c=.o)
OBJS_MANDATORY = $(OBJS_COMMON) $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#Rules
all : $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft DONE!$(RESET)"

$(NAME): $(LIBFT) $(OBJS_MANDATORY)
	@$(RM) $(NAME)
	@$(AR) $(NAME) $(OBJS_MANDATORY)
	@echo "$(NEON_GREEN)✓ Library $(NAME) DONE!$(RESET)"

bonus: $(LIBFT) $(OBJS_COMMON) $(OBJS_BONUS)
	@$(RM) $(NAME)
	@$(AR) $(NAME) $(OBJS_COMMON) $(OBJS_BONUS)
	@echo "$(NEON_GREEN)✓ Library $(NAME) with bonus DONE!$(RESET)"

#Compiling object files
%.o : %.c Makefile ft_printf.h
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@
	@echo "$(BLUE)	Compiled: $<$(RESET)"

clean :
	@$(RM) $(OBJS_COMMON) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@make -C $(LIBFT_DIR) clean
	@echo "$(CYAN)Object files removed$(RESET)"

fclean :
	@$(RM) $(OBJS_COMMON) $(OBJS_MANDATORY) $(OBJS_BONUS)
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(CYAN)All cleaned$(RESET)"

re : fclean all

.PHONY: all clean fclean re bonus
