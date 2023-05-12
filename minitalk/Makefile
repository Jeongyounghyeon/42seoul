# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 14:25:17 by youjeong          #+#    #+#              #
#    Updated: 2023/05/12 22:20:07 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror

# DIRECTORY
SRC_CLIENT_DIR = $(SRC_DIR)/client
SRC_SERVER_DIR = $(SRC_DIR)/server
SRC_SHARED_DIR = $(SRC_DIR)/shared
BUILD_DIR = build
BUILD_CLIENT_DIR = $(BUILD_DIR)/client
BUILD_SERVER_DIR = $(BUILD_DIR)/server
BUILD_SHARED_DIR = $(BUILD_DIR)/shared

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
SRCS_SHARED = shared.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_SHARED = $(SRCS_SHARED:.c=.o)

#LIBFT
LIBFT_DIR = libft
LIBFT_SRC_DIR = $(LIBFT_DIR)/src
LIBFT_A = $(LIBFT_DIR)/libft.a

# BONUS
SRCS_CLIENT_BONUS = client_bonus.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_SHARED_BONUS = shared_bonus.c
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_SHARED_BONUS = $(SRCS_SHARED_BONUS:.c=.o)

CLIENT = client
SERVER = server

ifdef BONUS
	SRC_DIR = src_bonus
	SRC_CLIENT = $(SRCS_CLIENT_BONUS)
	SRC_SERVER = $(SRCS_SERVER_BONUS)
	SRC_SHARED = $(SRCS_SHARED_BONUS)
	OBJ_CLIENT = $(OBJS_CLIENT_BONUS)
	OBJ_SERVER = $(OBJS_SERVER_BONUS)
	OBJ_SHARED = $(OBJS_SHARED_BONUS)
else
	SRC_DIR = src
	SRC_CLIENT = $(SRCS_CLIENT)
	SRC_SERVER = $(SRCS_SERVER)
	SRC_SHARED = $(SRCS_SHARED)
	OBJ_CLIENT = $(OBJS_CLIENT)
	OBJ_SERVER = $(OBJS_SERVER)
	OBJ_SHARED = $(OBJS_SHARED)
endif

all: $(BUILD_DIR) $(LIBFT_A) $(CLIENT) $(SERVER)

$(NAME): ${addprefix $(BUILD_DIR)/, $(OBJS)} 

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(BUILD_DIR):
	mkdir $@
	mkdir $(BUILD_CLIENT_DIR)
	mkdir $(BUILD_SERVER_DIR)
	mkdir $(BUILD_SHARED_DIR)

$(CLIENT): $(addprefix $(BUILD_SHARED_DIR)/, $(OBJ_SHARED)) $(addprefix $(BUILD_CLIENT_DIR)/, $(OBJ_CLIENT)) | $(BUILD_SHARED_DIR) $(BUILD_CLIENT_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT_A) -o $@


$(SERVER): $(addprefix $(BUILD_SHARED_DIR)/, $(OBJ_SHARED)) $(addprefix $(BUILD_SERVER_DIR)/, $(OBJ_SERVER)) | $(BUILD_SHARED_DIR) $(BUILD_SERVER_DIR)
	$(CC) $(CFLAGS) $^ $(LIBFT_A) -o $@

$(BUILD_SHARED_DIR)/%.o: $(SRC_SHARED_DIR)/%.c | $(BUILD_SHARED_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRC_DIR)/include \
								-I $(LIBFT_SRC_DIR)/include

$(BUILD_CLIENT_DIR)/%.o: $(SRC_CLIENT_DIR)/%.c | $(BUILD_CLIENT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRC_DIR)/include \
								-I $(LIBFT_SRC_DIR)/include
	
$(BUILD_SERVER_DIR)/%.o: $(SRC_SERVER_DIR)/%.c | $(BUILD_SHARED_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRC_DIR)/include \
								-I $(LIBFT_SRC_DIR)/include

bonus:
	make BONUS=1 all

clean:
	rm -rf $(BUILD_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	make clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	make fclean -C $(LIBFT_DIR)

re:
	make fclean
	make all

.PHONY: clean fclean re all bonus