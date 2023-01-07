/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:45:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/07 15:17:08 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
		else
			sign = 1;
	}	
	while (ft_isdigit(str[i]))
		res = (res * 10) + (str[i++] - '0');
	return (sign * res);
}
