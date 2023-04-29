# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 14:25:17 by youjeong          #+#    #+#              #
#    Updated: 2023/04/29 14:13:51 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

FD_SOURCE_BASIC = sources
FD_SOURCE_BONUS = sources_bonus

FD_OBJ_BASIC = objs
FD_OBJ_BONUS = objs_bonus

FD_HEADER = headers
FD_LIBFT = libft
FD_LIBFT_HEADER = $(FD_LIBFT)/headers
FD_GNL = get_next_line
FD_GNL_HEADER = $(FD_GNL)/headers

LIBFT_A = $(FD_LIBFT)/libft.a
GNL_A = $(FD_GNL)/get_next_line.a

SRCS_BASIC = so_long.c \
			map.c \
			validation.c \
			utils1.c \
			player.c
SRCS_BONUS = so_long.c

OBJS_BASIC = $(SRCS_BASIC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCS_BASIC = so_long.h
INCS_BONUS = so_long_bonus.h

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
	make -C $(FD_GNL)
	$(CC) $(CFLAGS) $(CLIB) $^ $(LIBFT_A) $(GNL_A) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

$(FD_OBJ):
	mkdir $@

$(FD_OBJ)/%.o: $(FD_SOURCE)/%.c
	$(CC) $(CFLAGS) -c  $^ -o $@ -I $(FD_HEADER) \
								-I $(FD_LIBFT_HEADER) \
								-I $(FD_GNL_HEADER)

bonus:
	make INPUT_BONUS=1 all

clean:
	rm -rf $(FD_OBJ_BASIC)
	rm -rf $(FD_OBJ_BONUS)
	make clean -C $(FD_LIBFT)
	make clean -C $(FD_GNL)

fclean:
	make clean
	rm -f $(NAME)
	make fclean -C $(FD_LIBFT)
	make fclean -C $(FD_GNL)

re:
	make fclean
	make all

.PHONY: clean fclean re all bonus