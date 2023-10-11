/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsubstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:37:33 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 16:41:54 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "xmem.h"

char	*xsubstr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		size = 0;
	else if (ft_strlen(s) - start < len)
		size = ft_strlen(s) - start;
	else
		size = len;
	dst = (char *)xmalloc(sizeof(char) * (size + 1));
	if (!s || !dst || len < 0)
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(s))
		dst[i++] = s[start++];
	dst[i] = 0;
	return (dst);
}
