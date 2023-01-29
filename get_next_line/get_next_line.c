/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:27:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/29 19:36:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_backup	*lst_backup = 0;
	t_backup		*backup;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = pop_backup(lst_backup, fd);
}
