/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:53:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/12 14:52:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

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
