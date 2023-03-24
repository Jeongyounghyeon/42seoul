/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:07:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/18 16:07:55 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isinstack(t_stack *stack, int data)
{
	t_node	*pnode;

	pnode = stack->top;
	while (pnode)
	{
		if (pnode->data == data)
			return (TRUE);
		pnode = pnode->next;
	}
	return (FALSE);
}

int	*stacktoarr(t_stack *stack)
{
	int		*res;
	int		i;
	t_node	*pnode;

	res = (int *)malloc((stack->cnt) * sizeof(int));
	if (!res)
		return (0);
	pnode = stack->top;
	i = 0;
	while (i < (stack->cnt))
	{
		res[i++] = pnode->data;
		pnode = pnode->next;
	}
	return (res);
}