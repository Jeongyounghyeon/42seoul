/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paly_cmd_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:02:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 12:09:14 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	play_sb(t_stack *stack)
{
	int	tmp;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
	return (0);
}

int	play_pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pnode;

	if (emptystack(stack_a))
		return (0);
	pnode = stack_a->top;
	stack_a->top = pnode->next;
	if (stack_a->top)
		stack_a->top->prev = 0;
	pnode->next = stack_b->top;
	if (emptystack(stack_b))
		stack_b->bottom = pnode;
	else
		stack_b->top->prev = pnode;
	stack_b->top = pnode;
	return (0);
}

int	play_rb(t_stack *stack)
{
	t_node	*pnode;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	pnode = stack->top;
	stack->top = pnode->next;
	stack->top->prev = 0;
	pnode->next = 0;
	pnode->prev = stack->bottom;
	stack->bottom->next = pnode;
	stack->bottom = pnode;
	return (0);
}

int	play_rrb(t_stack *stack)
{
	t_node	*pnode;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	pnode = stack->bottom;
	stack->bottom = pnode->prev;
	stack->bottom->next = 0;
	pnode->prev = 0;
	pnode->next = stack->top;
	stack->top->prev = pnode;
	stack->top = pnode;
	return (0);
}
