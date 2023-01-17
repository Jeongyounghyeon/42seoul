/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:27:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/17 21:03:12 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*res;
	char	c;
	ssize_t	res_read;

	res = 0;
	while (1)
	{
		res_read = read(fd, &c, BUFFER_SIZE);
		if (res_read == -1)
			return (0);
		else if (res_read == 0)
			return (res);
		if (!update_str_gnl(res, c))
			return (0);
		if (c == '\n')
			return (res);
	}
	return (0);
}
