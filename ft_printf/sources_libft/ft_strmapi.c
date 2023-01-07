/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:54:35 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/07 15:18:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	res = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = f((unsigned int)i, s[i]);
		i++;
	}
	res[len] = 0;
	return (res);
}
