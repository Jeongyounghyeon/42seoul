/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:52:37 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/26 19:28:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_start_num(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			*sign = -1;
		else
			*sign = 1;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		*sign = 0;
	}
	return (i);
}

int	ft_atoi(const char *str, int *oor)
{
	int		sign;
	int		i;
	long	res;

	sign = 1;
	*oor = 0;
	i = find_start_num(str, &sign);
	if (sign == 0)
	{
		*oor = -1;
		return (-1);
	}
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i++] - '0');
		if ((sign == -1 && res > 2147483648) || (sign == 1 && res > 2147483647))
		{
			*oor = -1;
			return (-1);
		}
	}
	if (str[i] != 0)
		*oor = -1;
	return (sign * res);
}
