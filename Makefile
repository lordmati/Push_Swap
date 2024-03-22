# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 17:38:49 by misaguir          #+#    #+#              #
#    Updated: 2024/03/22 15:59:08 by misaguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = Libft/

LIBFT = libft.a

SRCS_DIR = src #$(wildcard *.c)
OBJ_DIR	= obj

OBJ_DIR_BONUS = obj_bonus

SRCS_DIR_BONUS = src_bonus

FILES = src/main.c src/ft_atol.c src/ft_setup.c src/ft_movements_b.c src/ft_movements.c src/ft_moves_prints.c \
src/ft_moves.c src/ft_table.c src/ft_utils_ps.c src/ft_utils_ps2.c src/ft_utils_ps3.c src/ft_verification.c \

FILES_BONUS = src_bonus/main_bonus.c src_bonus/ft_atol_bonus.c src_bonus/ft_setup_bonus.c src_bonus/ft_movements_b_bonus.c src_bonus/ft_movements_bonus.c src_bonus/ft_moves_prints_bonus.c \
src_bonus/ft_moves_bonus.c src_bonus/ft_table_bonus.c src_bonus/ft_utils_ps_bonus.c src_bonus/ft_utils_ps2_bonus.c src_bonus/ft_utils_ps3_bonus.c src_bonus/ft_verification_bonus.c src_bonus/ft_checker_utils_bonus.c \

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

OBJS_SRCS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(FILES))

OBJS_SRCS_BONUS = $(patsubst %.c, $(OBJ_DIR_BONUS)/%.o, $(FILES_BONUS))

NAME = push_swap

NAME_BONUS = checker_bonus

INCLUDE = -I $(SRCS_DIR) -I $(LIBFT_DIR) -I $(SRCS_DIR_BONUS)

RM = rm -rf

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#Rules

$(NAME): $(OBJS_SRCS)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	@$(CC) $(INCLUDE) $(OBJS_SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_SRCS_BONUS)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	@$(CC) $(INCLUDE) $(OBJS_SRCS_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)
 
clean:
	@$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	make -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re bonus