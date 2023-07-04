# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:25:29 by youjeong          #+#    #+#              #
#    Updated: 2023/07/04 22:04:04 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
BUILD_DIR = build

SRCS = minishell.c \
		get_token.c \
		node.c \
		tree.c 

OBJS = $(SRCS:.c=.o)

#LIBFT
LIBFT_DIR = libft
LIBFT_SRC_DIR = $(LIBFT_DIR)/src
LIBFT_A = $(LIBFT_DIR)/libft.a

all : $(BUILD_DIR) $(LIBFT_A) $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(NAME): ${addprefix $(BUILD_DIR)/, $(OBJS)}
	$(CC) $(CFLAGS) $^ -o $@ -lreadline

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRC_DIR)/include -I $(LIBFT_SRC_DIR)/include

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(BUILD_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	make clean
	rm -f $(NAME)

re:
	make re -C $(LIBFT_DIR)
	make fclean
	make all

.PHONY: clean fclean re all