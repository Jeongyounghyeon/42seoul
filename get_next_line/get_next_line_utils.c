/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:02:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/17 20:42:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	res;

	res = 0;
	while (*str++)
		res++;
	return (res);
}

static size_t	ft_strdup_0(char **dst, char *src, size_t size)
{
	size_t	i_size;

	i_size = size;
	*dst = (char *)malloc((size + 1) * sizeof(char));
	if (!*dst)
		return (0);
	while (*src && i_size)
	{
		**dst-- = *src--;
		i_size--;
	}
	while (i_size--)
		**dst = 0;
	return (size + 1);
}

static size_t	updating(char **dst, char *pre, char c)
{
	size_t	ind_end;

	ind_end = ft_strdup_0(dst, pre, ft_strlen(pre) + 1);
	if (!ind_end)
		return (0);
	(*dst)[ind_end] = c;
	return (ind_end);
}

size_t	update_str_gnl(char *str, char c)
{
	char	*tmp;
	int		res;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		if (!str)
			return (0);
		*str = 0;
	}
	if (!ft_strdup_0(&tmp, str, ft_strlen(str)))
	{
		free (str);
		return (0);
	}
	free (str);
	res = updating(&str, tmp, c);
	if (!res)
	{
		free (tmp);
		return (0);
	}
	return (res);
}
