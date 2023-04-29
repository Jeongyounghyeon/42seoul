/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:53:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/21 15:54:18 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char				*ptr;
	const unsigned char	*s;

	if (dst == 0 && src == 0)
		return (0);
	ptr = dst;
	s = src;
	while (n--)
		*ptr++ = *s++;
	return (dst);
}
