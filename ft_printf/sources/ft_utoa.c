/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:22:26 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/12 18:19:43 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/headers/libft.h"

static int	len_digit(unsigned int u)
{
	int	res;

	res = 1;
	while (u / 10)
	{
		res++;
		u /= 10;
	}
	return (res);
}

char	*ft_utoa(unsigned int u)
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
		res[idx--] = (u % 10) + '0';
		u /= 10;
	}
	return (res);
}
