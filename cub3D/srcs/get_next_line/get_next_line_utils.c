/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:47:18 by juyyang           #+#    #+#             */
/*   Updated: 2023/09/20 19:46:51 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line.h"

t_fd_node	*get_fd_node(t_fd_node **head, int fd);
void		del_fd_node(t_fd_node **head, int fd);
size_t		length(const char *str);
ssize_t		find_newline(char *store);

t_fd_node	*get_fd_node(t_fd_node **head, int fd)
{
	t_fd_node	*iter;
	t_fd_node	*new_node;

	iter = *head;
	while (iter)
	{
		if (iter->fd == fd)
			return (iter);
		iter = iter->p_next;
	}
	new_node = malloc(sizeof(t_fd_node));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->backup = NULL;
	new_node->p_next = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		new_node->p_next = (*head);
		(*head) = new_node;
	}
	return (new_node);
}

void	del_fd_node(t_fd_node **head, int fd)
{
	t_fd_node	*iter;
	t_fd_node	*pre;

	iter = *head;
	pre = *head;
	while (iter)
	{
		if (iter->fd == fd)
		{
			if (iter == *head)
				*head = iter->p_next;
			pre->p_next = iter->p_next;
			pre = iter;
			if (pre->backup)
				free(pre->backup);
			free(pre);
			return ;
		}
		pre = iter;
		iter = iter->p_next;
	}
}

size_t	length(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
}

ssize_t	find_newline(char *store)
{
	ssize_t	idx;

	if (!store)
		return (FALSE);
	idx = 0;
	while (store[idx])
	{
		if (store[idx] == '\n')
			return (idx);
		idx++;
	}
	return (FALSE);
}
