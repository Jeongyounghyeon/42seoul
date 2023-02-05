/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:02:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/02/05 14:22:21 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t		res;

	if (!s)
		return (0);
	res = 0;
	while (*s++)
		res++;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;

	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == 0)
		return (0);
	i = 0;
	if (s1)
	{
		while (*s1)
		{
			res[i] = *s1++;
			i++;
		}
	}
	if (s2)
	{
		while (*s2)
		{
			res[i] = *s2++;
			i++;
		}
	}
	res[i] = 0;
	return (res);
}

t_backup	*add_backup(t_backup **lst_backup, int fd)
{
	t_backup	*new_backup;

	new_backup = (t_backup *)malloc(1 * sizeof(t_backup));
	if (!new_backup)
		return (0);
	new_backup->fd = fd;
	new_backup->buffer = 0;
	new_backup->next = *lst_backup;
	*lst_backup = new_backup;
	return (new_backup);
}

void	remove_backup(t_backup **lst_backup, int fd)
{
	t_backup	*pbackup;
	t_backup	*qbackup;

	pbackup = *lst_backup;
	while (pbackup)
	{
		if (pbackup->fd == fd)
		{
			if (pbackup == *lst_backup)
				*lst_backup = (*lst_backup)->next;
			else
				qbackup->next = pbackup->next;
			if (pbackup->buffer)
				free(pbackup->buffer);
			free(pbackup);
			break ;
		}
		qbackup = pbackup;
		pbackup = pbackup->next;
	}
}

t_backup	*find_add_backup(t_backup **lst_backup, int fd)
{
	t_backup	*pbackup;

	if (!(*lst_backup))
		return (add_backup(lst_backup, fd));
	pbackup = *lst_backup;
	while (pbackup->next)
	{
		if (pbackup->fd == fd)
			return (pbackup);
		pbackup = pbackup->next;
	}
	if (pbackup->fd == fd)
		return (pbackup);
	return (add_backup(lst_backup, fd));
}
