# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 16:00:16 by youjeong          #+#    #+#              #
#    Updated: 2023/01/11 20:28:54 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

FD_SOURCE = sources
FD_HEADER = headers
FD_OBJ = objs
FD_LIBFT = libft

SRCS = ft_init.c

OBJS = ${SRCS:.c=.o}
INCS = printf.h

ifdef INPUT_BONUS
 	OBJS_FILES = ${OBJS} ${OBJS_BONUS}
else
 	OBJS_FILES = ${OBJS}
endif

all : $(NAME)

$(NAME) : $(OBJS) 
	make -C $(FD_LIBFT)
	cp $(FD_LIBFT)/libft.a $(NAME)
	ar -rcus $@ ${addprefix $(FD_OBJ)/, $^}


%.o: ${FD_SOURCE}/%.c
	$(CC) $(CFLAGS) -c $^ -o $(FD_OBJ)/$@ -I ${FD_HEADER} 

bonus:
	make INPUT_BONUS=1 all

clean:
	rm -f ${addprefix $(FD_OBJ)/, $(OBJS)}
	make clean -C $(FD_LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(FD_LIBFT)

re: fclean all

.PHONY: clean fclean re all bonus