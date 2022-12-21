# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 14:11:47 by youjeong          #+#    #+#              #
#    Updated: 2022/12/21 15:56:18 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_bzero.c ~~~~~~
OBJS = $(SRCS: %.c=%.o)
SRCS_BONUS = ~~~~
OBJS_BONUS = 

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

$(OBJS) :
	$(CC) $(CFLAGS) -c $(SRCS)

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean 
	make all

bonus : $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^

.PHONY: clean fclean re all bonus