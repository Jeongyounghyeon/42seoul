/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:37:48 by juyyang           #+#    #+#             */
/*   Updated: 2023/09/04 17:25:34 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef CONTINUE
#  define CONTINUE 1
# endif

# ifndef EOF
#  define EOF 0
# endif

# ifndef ERROR
#  define ERROR -1
# endif

# ifndef FALSE
#  define FALSE -1
# endif

typedef struct s_fd_node
{
	int					fd;
	char				*backup;
	struct s_fd_node	*p_next;
}	t_fd_node;

char		*get_next_line(int fd);
t_fd_node	*get_fd_node(t_fd_node **head, int fd);
void		del_fd_node(t_fd_node **head, int fd);
size_t		length(const char *str);
ssize_t		find_newline(char *store);

#endif
