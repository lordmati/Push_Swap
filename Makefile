# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misaguir <misaguir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 17:38:49 by misaguir          #+#    #+#              #
#    Updated: 2024/02/28 15:59:09 by misaguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = Libft/

LIBFT = libft.a

SRCS =  $(wildcard *.c)

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

OBJS_SRCS = $(SRCS:.c=.o)

NAME = push_swap

INCLUDE = -I . -I $(LIBFT_DIR)

RM = rm -rf

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ 

#Rules

$(NAME): $(OBJS_SRCS)
	@$(MAKE) -s all bonus printf -C $(LIBFT_DIR)
	@$(CC) $(INCLUDES) $(OBJS_SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)
 
clean:
	@$(RM) $(OBJS_SRCS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re