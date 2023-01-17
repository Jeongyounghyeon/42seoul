/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:36:43 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/14 20:21:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	res;

	res = 0;
	res += write(fd, s, ft_strlen(s));
	if (res == -1)
		return (res);
	res += write(fd, "\n", 1);
	return (res);
}
