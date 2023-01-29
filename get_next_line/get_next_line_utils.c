/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:02:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/29 21:41:49 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		res;

	res = 0;
	while (*s)
	{
		res++;
		s++;
	}
	return (res);
}

int	find_nl(char *buffer)
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

char	*strjoin_endc(char *str1, char *str2, char c)
{
	char	*res;
	char	*plstr;
	char	*pres;
	int		len;

	len = 0;
	plstr = str1;
	while (plstr && *plstr && (*plstr++ != c))
		len++;
	plstr = str2;
	while (plstr && *plstr && (*plstr++ != c))
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	pres = res;
	plstr = str1;
	while (plstr && *plstr && (*plstr != c))
		*pres++ = plstr++;
	plstr = str2;
	while (plstr && *plstr && (*plstr != c))
		*pres++ = plstr++;
	return (res);
}

t_backup	*add_backup(t_backup **lst_backup, t_backup *backup, int fd)
{
	t_backup	*new_backup;
	
	if (!backup)
		new_backup = backup;
	else
	{
		new_backup = (t_backup *)malloc(1 * sizeof(t_backup));
		if (!new_backup)
			return (0);
		new_backup->buffer = 0;
		new_backup->buffer = (char *)malloc((BUFFER_SIZE * 1) * sizeof(char));
		if (!(new_backup->buffer))
		{
			free (new_backup);
			return (0);
		}
		(new_backup->buffer)[0] = 0;
	}
	new_backup->fd = fd;
	new_backup->next = *lst_backup;
	*lst_backup = new_backup;
	return (new_backup);
}

t_backup	*pop_backup(t_backup **lst_backup, int fd)
{
	t_backup	*pop_backup;
	t_backup	*qoq_backup;

	pop_backup = *lst_backup;
	qoq_backup = *lst_backup;
	while (pop_backup)
	{
		qoq_backup = pop_backup;
		if (pop_backup->fd == fd)
		{
			if (pop_backup == *lst_backup)
			{
				*lst_backup = pop_backup->next;
				return (pop_backup);
			}
			else
			{
				qoq_backup->next = pop_backup->next;
				return (pop_backup);
			}
		}
		pop_backup = pop_backup->next;
	}
	return (0);
}

t_backup	*pop_backup2(t_backup **lst_backup, int fd)
{
	t_backup	*pbackup;

	if (!(*lst_backup))
		return (0);
	pbackup = *lst_backup;
	while ((pbackup->next) && (pbackup->fd != fd))
		pbackup = pbackup->next;
	if (pbackup->fd == fd)
		
}