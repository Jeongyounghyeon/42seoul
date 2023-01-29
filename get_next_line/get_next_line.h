/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:25:57 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/29 17:06:36 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

typedef struct s_backup
{
	int			fd;
	char		*buffer;
	t_backup	*next;
}t_backup;

size_t		ft_strlen(const char *s);
int			find_nl(char *buffer);
char		*strjoin_endc(char *str1, char *str2, char c);
t_backup	*add_backup(t_backup **lst_backup, t_backup *backup, int fd);
t_backup	*pop_backup(t_backup **lst_backup, int fd);

#endif