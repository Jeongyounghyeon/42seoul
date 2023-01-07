# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 16:00:16 by youjeong          #+#    #+#              #
#    Updated: 2023/01/07 15:14:50 by youjeong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FD_LIBFT = sources_libft
FD_PRINTF = sources
FD_HEADER = headers

SRCS_LIBFT = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJS_LIBFT = ${FD_LIBFT}/${SRCS_LIBFT:.c=.o}
INCS = ${FD_HEADER}/libft.h

# ifdef INPUT_BONUS
# 	OBJS_FILES = ${OBJS} ${OBJS_BONUS}
# else
# 	OBJS_FILES = ${OBJS}
#endif

all : $(NAME)

# $(NAME) : $(OBJS_FILES)
# 	ar -rcus $@ $^

$(NAME) : $(OBJS_LIBFT)
	ar -rcus $@ $^

%.o: ${FD_LIBFT}/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -include $(INCS)

bonus:
	make INPUT_BONUS=1 all

# clean:
# 	rm -f $(OBJS) $(OBJS_BONUS)

clean:
	rm -f $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus