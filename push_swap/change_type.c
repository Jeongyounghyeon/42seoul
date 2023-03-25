/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:41:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 13:41:46 by youjeong         ###   ########.fr       */
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

int	*stacktoarr(t_stack *stack)
{
	int		*res;
	int		i;
	t_node	*pnode;

	res = (int *)malloc((len_stack(stack)) * sizeof(int));
	if (!res)
		return (0);
	pnode = stack->top;
	i = 0;
	while (i < (len_stack(stack)))
	{
		res[i++] = pnode->data;
		pnode = pnode->next;
	}
	return (res);
}
