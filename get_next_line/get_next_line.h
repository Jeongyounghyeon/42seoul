/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:25:57 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/30 21:26:53 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_backup
{
	int				fd;
	char			*buffer;
	struct s_backup	*next;
}t_backup;

char	*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
t_backup	*add_backup(t_backup **lst_backup, int fd);
void	remove_backup(t_backup **lst_backup, int fd);
t_backup	*find_add_backup(t_backup **lst_backup, int fd);

#endif