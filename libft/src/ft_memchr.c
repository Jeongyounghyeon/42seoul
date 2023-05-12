/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:54:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/17 16:14:13 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{	
	size_t			i;
	unsigned char	*s_tmp;

	s_tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s_tmp[i] == (unsigned char)c)
			return (s_tmp + i);
		i++;
	}
	return (0);
}
