/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:33:54 by youjeong          #+#    #+#             */
/*   Updated: 2022/12/26 16:46:41 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*s;

	if (dst <= src)
	{
		tmp = dst;
		s = src;
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		tmp = dst;
		tmp += len;
		s = src;
		s += len;
		while (len--)
			*--tmp = *--s;
	}
	return (dst);
}
