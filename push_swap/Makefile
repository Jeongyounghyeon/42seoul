
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 10:13:04 by youjeong          #+#    #+#              #
#    Updated: 2023/03/24 10:13:04 by youjeong         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FD_OBJ_BASIC = objs
FD_OBJ_BONUS = objs_bonus

SRCS_BASIC = push_swap.c \
			input_to_stack.c \
			show_sorting_stack.c \
			sort_stack_a.c \
			sort_stack_b.c \
			sort_hard_a.c \
			sort_hard_b.c \
			merge_sort.c \
			cmd_a.c \
			cmd_b.c \
			cmd_sim.c \
			ft_split_space.c \
			ft_atoi.c \
			print_cmds.c \
			stack.c \
			stack_func.c \
			free_type.c \
			utils1.c \
			utils2.c \
			optimization.c \
			optimization_cmd_a.c \
			optimization_cmd_b.c \
			utils_code.c

SRCS_BONUS = checker.c \
			input_to_stack.c \
			show_sorting_stack.c \
			sort_stack_a.c \
			sort_stack_b.c \
			sort_hard_a.c \
			sort_hard_b.c \
			merge_sort.c \
			cmd_a.c \
			cmd_b.c \
			cmd_sim.c \
			ft_split_space.c \
			ft_atoi.c \
			print_cmds.c \
			stack.c \
			stack_func.c \
			free_type.c \
			utils1.c \
			utils2.c \
			optimization.c \
			optimization_cmd_a.c \
			optimization_cmd_b.c \
			utils_code.c \
			get_next_line.c \
			get_next_line_utils.c \
			check_command.c \
			play_cmd_a.c \
			play_cmd_b.c \
			play_cmd_sim.c \

OBJS_BASIC = $(SRCS_BASIC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCS_BASIC = push_swap.h
INCS_BONUS = checker.h

ifdef INPUT_BONUS
		PR_NAME = $(NAME_BONUS)
        FD_OBJ = $(FD_OBJ_BONUS)
        SRCS = $(SRCS_BONUS)
        OBJS = $(OBJS_BONUS)
        INCS = $(INCS_BONUS)
else
		PR_NAME = $(NAME)
        FD_OBJ = $(FD_OBJ_BASIC)
        SRCS = $(SRCS_BASIC)
        OBJS = $(OBJS_BASIC)
        INCS = $(INCS_BASIC)
endif

all : $(FD_OBJ) $(PR_NAME)

$(PR_NAME) : ${addprefix $(FD_OBJ)/, $(OBJS)}
		$(CC) $(CFLAGS) $^ -o $(PR_NAME)

$(FD_OBJ):
		mkdir $@

bonus:
	make INPUT_BONUS=1 all

$(FD_OBJ)/%.o: %.c
		$(CC) $(CFLAGS) -c $^ -o $@ -include $(INCS)

clean:
		rm -rf $(FD_OBJ_BASIC)
		rm -rf $(FD_OBJ_BONUS)

fclean: clean
		rm -f $(NAME)
		rm -f $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus