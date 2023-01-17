/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:42:57 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/17 16:14:42 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	dstl;
	size_t	srcl;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	i_dest = dstl;
	i_src = 0;
	while (src[i_src] && (i_src + dstl + 1) < dstsize)
	{
		dst[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dst[i_dest] = '\0';
	if (dstl < dstsize)
		return (srcl + dstl);
	else
		return (srcl + dstsize);
}
