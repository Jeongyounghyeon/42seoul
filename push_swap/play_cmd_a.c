/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:57:13 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 11:59:40 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	play_sa(t_stack *stack)
{
	int	tmp;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
	return (0);
}

int	play_pa(t_stack *stack_b, t_stack *stack_a)
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
	return (0);
}

int	play_ra(t_stack *stack)
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

int	play_rra(t_stack *stack)
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
