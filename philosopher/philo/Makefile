# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:25:29 by youjeong          #+#    #+#              #
#    Updated: 2023/06/12 20:26:42 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
BUILD_DIR = build

SRCS = philo.c \
		input_handler.c \
		set_philo.c \
		init.c \
		routine.c \
		exception.c \
		monitoring.c \
		utils.c \
		ft_atoi.c \

OBJS = $(SRCS:.c=.o)

all : $(BUILD_DIR) $(NAME)

$(NAME): ${addprefix $(BUILD_DIR)/, $(OBJS)}
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRC_DIR)/include

clean:
	rm -rf $(BUILD_DIR)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: clean fclean re all