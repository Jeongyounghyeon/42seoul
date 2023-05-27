/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:50:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/27 14:59:17 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_strlen(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
char    *ft_strjoin(char const *s1, char const *s2);

int	ft_strlen(const char *s)
{
	int		res;

	if (!s)
		return (0);
	res = 0;
	while (*s++)
		res++;
	return (res);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t  i;
	size_t  srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (!dst || !src)
			return (0);
	while ((i < srcsize) && (i + 1 < dstsize))
	{
			dst[i] = src[i];
			i++;
	}
	if (dstsize > 0)
			dst[i] = 0;
	return (srcsize);
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t  i_dest;
	size_t  i_src;
	size_t  dstl;
	size_t  srcl;

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

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *res;
	size_t  s1_len;
	size_t  s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (res == 0)
			return (0);
	ft_strlcpy(res, s1, s1_len + 1);
	ft_strlcat(res, s2, s1_len + s2_len + 1);
	res[s1_len + s2_len] = 0;
	return (res);
}
