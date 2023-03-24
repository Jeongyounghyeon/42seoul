/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:36:40 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 10:36:40 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*dequetoarr(t_deque *deque)
{
	int		*res;
	int		i;
	t_node	*pnode;

	res = (int *)malloc((deque->cnt) * sizeof(int));
	if (!res)
		return (0);
	pnode = deque->top;
	i = 0;
	while (i < (deque->cnt))
	{
		res[i++] = pnode->data;
		pnode = pnode->next;
	}
	return (res);
}
