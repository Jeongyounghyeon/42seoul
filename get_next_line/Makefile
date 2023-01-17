# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 16:00:16 by youjeong          #+#    #+#              #
#    Updated: 2023/01/17 20:54:05 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

FD_SOURCE_BASIC = sources
FD_SOURCE_BONUS = sources_bonus

FD_OBJ_BASIC = objs
FD_OBJ_BONUS = objs_bonus

FD_HEADER = headers
FD_LIBFT = libft

SRCS_BASIC = get_next_line.c \
			get_next_line_utils.c
SRCS_BONUS = get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJS_BASIC = $(SRCS_BASIC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCS_BASIC = get_next_line.h
INCS_BONUS = get_next_line_bonus.h

ifdef INPUT_BONUS
	FD_SOURCE = $(FD_SOURCE_BONUS)
	FD_OBJ = $(FD_OBJ_BONUS)
	SRCS = $(SRCS_BONUS)
	OBJS = $(OBJS_BONUS)
	INCS = $(INCS_BONUS)
else
	FD_SOURCE = $(FD_SOURCE_BASIC)
	FD_OBJ = $(FD_OBJ_BASIC)
	SRCS = $(SRCS_BASIC)
	OBJS = $(OBJS_BASIC)
	INCS = $(INCS_BASIC)
endif


all : $(FD_OBJ) $(NAME)

$(NAME) : ${addprefix $(FD_OBJ)/, $(OBJS)}
	ar -rcus $@ $^

$(FD_OBJ):
	mkdir $@

$(FD_OBJ)/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(FD_HEADER) 

bonus:
	make INPUT_BONUS=1 all

clean:
	rm -rf $(FD_OBJ_BASIC)
	rm -rf $(FD_OBJ_BONUS)

fclean: 
	make clean
	rm -f $(NAME)

re: 
	make fclean 
	make all

.PHONY: clean fclean re all bonus