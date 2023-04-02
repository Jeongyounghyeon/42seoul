/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:39:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/02 18:51:06 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_sa(t_stack *stack, t_stack *stack_cmd)
{
	int	tmp;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
	if (optimization_cmd_sa(stack, stack_cmd))
		return (ERROR);
	return (0);
}

int	cmd_pa(t_stack *stack_b, t_stack *stack_a, t_stack *stack_cmd)
{
	t_node	*pnode;

	if (emptystack(stack_b))
		return (0);
	pnode = stack_b->top;
	stack_b->top = pnode->next;
	if (stack_b->top)
		stack_b->top->prev = 0;
	pnode->next = stack_a->top;
	if (emptystack(stack_a))
		stack_a->bottom = pnode;
	else
		stack_a->top->prev = pnode;
	stack_a->top = pnode;
	if (stack_cmd->top && stack_cmd->top->data == pb)
		pop_top(stack_cmd);
	else if (push_top(stack_cmd, pa) == ERROR)
		return (ERROR);
	return (0);
}

int	cmd_ra(t_stack *stack, t_stack *stack_cmd)
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
	if (optimization_cmd_ra(stack_cmd))
		return (ERROR);
	return (0);
}

int	cmd_rra(t_stack *stack, t_stack *stack_cmd)
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
	if (optimization_cmd_rra(stack_cmd))
		return (ERROR);
	return (0);
}
