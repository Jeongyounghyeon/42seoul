/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:59:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/13 17:59:52 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf_bonus.h"
#include "../libft/headers/libft.h"

static int	len_digit(unsigned int u)
{
	int	res;

	res = 1;
	while (u / 16)
	{
		res++;
		u /= 16;
	}
	return (res);
}

char	*ft_utohex(unsigned int u, int upc)
{
	char		*res;
	int			len;

	len = len_digit(u);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	res[len] = 0;
    while (u)
	{
		if (upc)
			res[idx--] = "0123456789ABCDEF"[u % 16];
		else
			res[idx--] = "0123456789abcdef"[u % 16];
		u /= 16;
	}
	return (res);
}

