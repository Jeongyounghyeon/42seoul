/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:49:09 by juyyang           #+#    #+#             */
/*   Updated: 2023/09/20 19:47:02 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line.h"

static void	*update_str(char *old, char *add, size_t start, size_t end)
{
	char	*new;
	size_t	i;

	if (!length(add))
		return (old);
	new = malloc(sizeof(char) * (length(old) + (end - start) + 1));
	if (new)
	{
		i = 0;
		if (old)
		{
			while (old[i])
			{
				new[i] = old[i];
				i++;
			}
		}
		while (add[start] && start < end)
			new[i++] = add[start++];
		new[i] = 0;
	}
	if (old)
		free(old);
	old = 0;
	return (new);
}

static int	update_buffer(char *buf, char **p_line, t_fd_node *fd_node)
{
	ssize_t	nl_idx;
	ssize_t	offset;

	nl_idx = find_newline(buf);
	offset = length(buf);
	fd_node->backup = update_str(fd_node->backup, buf, 0, nl_idx + 1);
	if (!fd_node->backup)
		return (ERROR);
	*p_line = update_str(*p_line, fd_node->backup, 0, length(fd_node->backup));
	if (!*p_line)
		return (ERROR);
	if (fd_node->backup)
		free(fd_node->backup);
	fd_node->backup = update_str(0, buf, nl_idx + 1, offset);
	if (!fd_node->backup)
		return (ERROR);
	return (1);
}

static int	read_file(int fd, char *buf, char **p_line, t_fd_node *fd_node)
{
	ssize_t	offset;

	while (1)
	{
		offset = read(fd, buf, BUFFER_SIZE);
		if (offset < 0)
			return (ERROR);
		buf[offset] = '\0';
		if (find_newline(buf) != FALSE)
			return (update_buffer(buf, p_line, fd_node));
		else if (offset == 0)
		{
			if (length(fd_node->backup))
			{
				*p_line = update_str(*p_line,
						fd_node->backup, 0, length(fd_node->backup));
				if (!(*p_line))
					return (ERROR);
			}
			return (EOF);
		}
		fd_node->backup = update_str(fd_node->backup, buf, 0, offset);
		if (!fd_node->backup)
			return (ERROR);
	}
}

static int	read_backup(int fd, char *buffer, char **p_line, t_fd_node *fd_node)
{
	ssize_t	idx_newline;
	char	*old_backup;

	if (!buffer || !fd_node)
		return (ERROR);
	idx_newline = find_newline(fd_node->backup);
	if (idx_newline != FALSE)
	{
		*p_line = update_str(*p_line, fd_node->backup, 0, idx_newline + 1);
		if (!*p_line)
			return (ERROR);
		old_backup = fd_node->backup;
		fd_node->backup = update_str(0,
				fd_node->backup, idx_newline + 1, length(fd_node->backup));
		if (old_backup)
			free(old_backup);
		if (!fd_node->backup)
			return (ERROR);
		return (CONTINUE);
	}
	else
		return (read_file(fd, buffer, p_line, fd_node));
}

char	*get_next_line(int fd)
{
	static t_fd_node	*fd_nodes;
	char				*buffer;
	char				*line;
	int					status;

	line = NULL;
	status = ERROR;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	status = read_backup(fd, buffer, &line, get_fd_node(&fd_nodes, fd));
	if (status == ERROR || status == EOF)
	{
		del_fd_node(&fd_nodes, fd);
		if (status == ERROR)
		{
			if (line)
				free(line);
			line = NULL;
		}
	}
	if (buffer)
		free(buffer);
	return (line);
}
