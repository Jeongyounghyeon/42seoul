# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 16:00:16 by youjeong          #+#    #+#              #
#    Updated: 2023/01/14 16:20:08 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

FD_SOURCE_BASIC = sources
FD_SOURCE_BONUS = sources_bonus

FD_OBJ_BASIC = objs
FD_OBJ_BONUS = objs_bonus

FD_HEADER = headers
FD_LIBFT = libft

SRCS_BASIC = ft_printf.c \
			ft_print_c1.c \
			ft_print_c2.c \
			ft_utoa.c \
			ft_utop.c\
			ft_utohex.c\
			
			
SRCS_BONUS = ft_printf.c \
			ft_print_c1.c \
			ft_print_c2.c \
			ft_utoa.c \
			ft_utop.c\
			ft_utohex.c\

OBJS_BASIC = $(SRCS_BASIC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCS_BASIC = ft_printf.h
INCS_BONUS = ft_printf_bonus.h

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
	make -C $(FD_LIBFT)
	cp $(FD_LIBFT)/libft.a $(NAME)
	ar -rcus $@ $^

$(FD_OBJ):
	mkdir $@

$(FD_OBJ)/%.o: $(FD_SOURCE)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(FD_HEADER) 

bonus:
	make INPUT_BONUS=1 all

clean:
	rm -rf $(FD_OBJ_BASIC)
	rm -rf $(FD_OBJ_BONUS)
	make clean -C $(FD_LIBFT)

fclean: 
	make clean
	rm -f $(NAME)
	make fclean -C $(FD_LIBFT)

re: 
	make fclean 
	make all

.PHONY: clean fclean re all bonus