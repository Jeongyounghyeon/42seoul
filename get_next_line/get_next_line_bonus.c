/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:13:46 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/29 14:44:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_backup	*find_backup(t_backup *lst_backup, int fd)
{
	t_backup	*plst_backup;

	plst_backup = lst_backup;
	while(plst_backup)
	{
		if (plst_backup->fd == fd)
			return (plst_backup);
		plst_backup = plst_backup->next;
	}
	return (0);
}

static t_backup	*add_backup(t_backup **lst_backup, int fd)
{
	t_backup	*new_backup;

	new_backup = 0;
	new_backup = (t_backup *)malloc(1 * sizeof(t_backup));
	if (!new_backup)
		return (0);
	new_backup->fd = fd;
	new_backup->buffer = (char *)malloc(1 * sizeof(char));
	if (!new_backup->buffer)
	{
		free(new_backup);
		return (0);
	}
	(new_backup->buffer)[0] = 0;
	new_backup->next = *lst_backup;
	*lst_backup = new_backup;
	return (new_backup);
}

static t_backup *pop_backup(t_backup **lst_backup, int fd)
{
	t_backup	*pbu;
	t_backup	*qbu;

	pbu = *lst_backup;
	qbu = 0;
	while (pbu && (pbu->fd != fd))
	{
		qbu = pbu;
		pbu = pbu->next;
	}
	if (pbu)
	{
		if (pbu == *lst_backup)
			*lst_backup = pbu->next;
		else
			qbu->next = pbu->next;
	}
	return (pbu);
}

static int	find_nl(char *buffer)
{
	int	ind;

	ind = 0;
	while (buffer[ind])
	{
		if (buffer[ind] == '\n')
			return (ind);
		ind++;
	}
	return (-1);	
}

char	*get_next_line(int fd)
{
	static t_backup	*lst_backup = 0;
	t_backup		*backup;
	char			*buffer;
	char			*line;
	int				ind_nl;
	ssize_t			res_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[0] = 0;
	backup = find_backup(lst_backup, fd);
	if (!backup)
		backup = add_backup(&lst_backup, fd);
	ind_nl = find_nl(backup->buffer);									// 기존 backup 개행 찾기
	if (ind_nl == -1)														// 기존 개행이 없으면
	{
		res_read = BUFFER_SIZE;
		while ((res_read == BUFFER_SIZE) && (ind_nl == -1))
		{
			update_buffer(backup->buffer, buffer);
			res_read = read(fd, buffer, BUFFER_SIZE);					// 일단 읽고
			if (res_read == -1)
			{
				free(buffer);
				free(pop_backup(lst_backup, fd));
				return (0);
			}
			buffer[res_read] = 0;
			ind_nl = find_nl(buffer);
		}
		if (res_read == -1)
		{
			free(buffer);
			free(pop_backup(lst_backup, fd));
			return (0);
		}
		update_buffer(backup->buffer, buffer);
		line = backup->buffer;
		backup->buffer = 0;
	}
	else
	{
		
	}
	free(buffer);
}
