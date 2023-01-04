# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 16:00:16 by youjeong          #+#    #+#              #
#    Updated: 2023/01/04 16:02:22 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c
SRCS_BONUS = 
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
INCS = libft.h \
		printf.h

ifdef INPUT_BONUS
	OBJS_FILES = ${OBJS} ${OBJS_BONUS}
else
	OBJS_FILES = ${OBJS}
endif

all : $(NAME)

$(NAME) : $(OBJS_FILES)
	ar -rcus $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -include $(INCS)

bonus:
	make INPUT_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus