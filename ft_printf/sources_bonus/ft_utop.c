/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:52:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/14 17:34:33 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static int	len_digit(size_t u)
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

char	*ft_utop(size_t u)
{
	char	*res;
	int		len;

	len = len_digit(u);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	res[len] = 0;
	while (len--)
	{
		res[len] = "0123456789abcdef"[u % 16];
		u /= 16;
	}
	return (res);
}
