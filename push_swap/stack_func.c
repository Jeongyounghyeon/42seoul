/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:06:14 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/27 20:21:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_top(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = getnode();
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->next = stack->top;
	if (stack->top == 0)
		stack->bottom = new_node;
	else
		new_node->next->prev = new_node;
	stack->top = new_node;
	return (0);
}

int	push_bottom(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = getnode();
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->prev = stack->bottom;
	if (stack->top == 0)
		stack->top = new_node;
	else
		new_node->prev->next = new_node;
	stack->bottom = new_node;
	return (0);
}

int	pop_top(t_stack *stack)
{
	t_node	*pop_node;
	int		pop_data;

	if (emptystack(stack))
	{
		write(1, "\npop_top : emptystack\n", 22);
		exit(1);
	}
	pop_node = stack->top;
	stack->top = stack->top->next;
	if (stack->top == 0)
		stack->bottom = 0;
	else
		stack->top->prev = 0;
	pop_data = pop_node->data;
	free(pop_node);
	return (pop_data);
}

int	pop_bottom(t_stack *stack)
{
	t_node	*pop_node;
	int		pop_data;

	if (emptystack(stack))
	{
		write(1, "\npop_bottom : emptystack\n", 25);
		exit(1);
	}
	pop_node = stack->bottom;
	stack->bottom = stack->bottom->prev;
	if (stack->bottom == 0)
		stack->top = 0;
	else
		stack->bottom->next = 0;
	pop_data = pop_node->data;
	free(pop_node);
	return (pop_data);
}
