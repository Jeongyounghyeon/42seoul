/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:26:33 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/27 22:12:27 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int		res;

	res = 0;
	while (*s)
	{
		res++;
		s++;
	}
	return (res);
}

char	*update_buffer(char const *s1, char const *s2)
{
	char	*res;
	char	*ps1;
	char	*ps2;
	char	*pres;
	size_t	len;
	
	len = ft_strlen(s1);
	while ((*ps2) && (*ps2++ != '\n'))
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	pres = res;
	ps1 = s1;
	while (*ps1)
		*pres++ = *ps1++;
	ps2 = s2;
	while (*ps2 && (*ps2 != '\n'))
		*pres++ = *ps2++;
	*pres = 0;
	free(s1);
	return (res);
}