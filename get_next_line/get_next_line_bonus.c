/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:13:46 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/30 23:09:09 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	find_nl(char *buffer)
{
	int	ind;

	if (!buffer)
		return (-1);
	ind = 0;
	while (buffer[ind])
	{
		if (buffer[ind] == '\n')
			return (ind);
		ind++;
	}
	return (-1);	
}

char	*ft_strldup(char *str, size_t size)
{
	char	*res;
	size_t	i;

	if (!str)
		return (0);
	res = 0;
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (*str && (i < size))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static int	read_nl(t_backup *backup, int fd)
{
	char	*buffer;
	char	*rm_buffer;
	int		rd;
	int		ind_nl;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	rd = read(fd, buffer, BUFFER_SIZE);
	ind_nl = -1;
	while ((rd > 0) && (ind_nl == -1))
	{
		buffer[rd] = 0;
		ind_nl = find_nl(buffer);
		rm_buffer = backup->buffer;
		backup->buffer = ft_strjoin(backup->buffer, buffer);
		free(rm_buffer);
		if (ft_strlen(backup->buffer) == 0)
			break ;
		rd = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (rd == -1)
		return (0);
	return (1);
}

static char	*get_line(t_backup *backup, int fd)
{
	char	*line;
	char	*rm_buffer;
	int		ind_nl;

	ind_nl = find_nl(backup->buffer);
	if (ind_nl == -1)
	{
		if (!read_nl(backup, fd))
		{
			if (backup->buffer)
				free(backup->buffer);
			return (0);
		}
		ind_nl = find_nl(backup->buffer);
	}
	if (ind_nl == -1)
		ind_nl = ft_strlen(backup->buffer) - 1;
	line = ft_strldup(backup->buffer, ind_nl + 1);
	rm_buffer = backup->buffer;
	backup->buffer = ft_strjoin((backup->buffer) + ind_nl + 1, "");
	free(rm_buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_backup	*lst_backup = 0;
	t_backup		*backup;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = 0;	
	backup = find_add_backup(&lst_backup, fd);
	if (!backup)
		return (0);
	line = get_line(backup, fd);
	if (ft_strlen(backup->buffer) == 0)
		remove_backup(&lst_backup, fd);
	return (line);
}

