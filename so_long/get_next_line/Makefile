# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 14:11:47 by youjeong          #+#    #+#              #
#    Updated: 2023/04/21 15:50:14 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FD_SOURCE = sources
FD_HEADER = headers
FD_OBJ = objs

SRCS = get_next_line.c \
		get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(FD_OBJ) $(NAME)

$(NAME) : ${addprefix $(FD_OBJ)/, $(OBJS)}
	ar -rcus $@ $^

$(FD_OBJ):
	mkdir $@

$(FD_OBJ)/%.o: $(FD_SOURCE)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(FD_HEADER) 

clean:
	rm -rf $(FD_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all