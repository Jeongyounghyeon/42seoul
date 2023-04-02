/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:39:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/02 18:51:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_sb(t_stack *stack, t_stack *stack_cmd)
{
	int	tmp;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
	if (optimization_cmd_sb(stack, stack_cmd))
		return (ERROR);
	return (0);
}

int	cmd_pb(t_stack *stack_a, t_stack *stack_b, t_stack *stack_cmd)
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
	if (stack_cmd->top && stack_cmd->top->data == pa)
		pop_top(stack_cmd);
	else if (push_top(stack_cmd, pb) == ERROR)
		return (ERROR);
	return (0);
}

int	cmd_rb(t_stack *stack, t_stack *stack_cmd)
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
	if (optimization_cmd_rb(stack_cmd))
		return (ERROR);
	return (0);
}

int	cmd_rrb(t_stack *stack, t_stack *stack_cmd)
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
	if (optimization_cmd_rrb(stack_cmd))
		return (ERROR);
	return (0);
}
