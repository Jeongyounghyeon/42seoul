# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 18:26:22 by youjeong          #+#    #+#              #
#    Updated: 2023/03/20 19:57:52 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FD_OBJ = objs

SRCS = stack_func1.c \
		stack_func2.c \
		stack.c \
		utils1.c \
		utils2.c \
		valid.c \
		make_stack.c \
		ft_split.c \
		free_type.c \
		cmd_execute.c \
		cmd_a.c \
		cmd_b.c \
		cmd_sim.c
OBJS = $(SRCS:.c=.o)

all : $(FD_OBJ) $(NAME)

$(NAME) : ${addprefix $(FD_OBJ)/, $(OBJS)}
		ar -rcus $@ $^

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