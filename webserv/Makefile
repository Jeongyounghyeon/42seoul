# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 18:29:21 by youjeong          #+#    #+#              #
#    Updated: 2023/12/21 17:09:30 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = webserv

CXX = c++
RM = rm -f

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
INCLUDE = -I $(HEADER_DIR) 

SRC_DIR = src
HEADER_DIR = $(SRC_DIR)/include
OBJ_DIR = obj

SRCS = $(addprefix src/, main.cpp \
						config/Config.cpp \
						config/ConfigServer.cpp \
						config/ConfigLocation.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

$(OBJ_DIR):
	find $(SRC_DIR) -mindepth 1 -type d ! -path "$(HEADER_DIR)" \
	-exec sh -c 'mkdir -p ${OBJ_DIR}/$${0#${SRC_DIR}/}' {} \;

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all