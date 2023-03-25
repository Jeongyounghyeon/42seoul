/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:34:32 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 13:00:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*getnode(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = 0;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	initstack(t_stack *stack)
{
	stack->top = 0;
	stack->bottom = 0;
}

int	emptystack(t_stack *stack)
{
	if ((stack->top) == 0)
		return (TRUE);
	else
		return (FALSE);
}

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

int	len_stack(t_stack *stack)
{
	int		res;
	t_node	*pnode;

	res = 0;
	pnode = stack->top;
	while (pnode)
	{
		res++;
		pnode = pnode->next;
	}
	return (res);
}
