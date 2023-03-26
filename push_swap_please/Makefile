
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 10:13:04 by youjeong          #+#    #+#              #
#    Updated: 2023/03/24 10:13:04 by youjeong         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FD_OBJ = objs

SRCS = push_swap.c \
		input_to_stack.c \
		ft_split_space.c \
		ft_atoi.c \
		stack.c \
		stack_func.c \
		free_type.c \
		utils1.c \
		utils2.c \


OBJS = $(SRCS:.c=.o)

all : $(FD_OBJ) $(NAME)

$(NAME) : ${addprefix $(FD_OBJ)/, $(OBJS)}
		$(CC) $(CFLAGS) $^ -o $@

$(FD_OBJ):
		mkdir $@

$(FD_OBJ)/%.o: %.c
		$(CC) $(CFLAGS) -c $^ -o $@ -include push_swap.h

clean:
		rm -rf $(FD_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all