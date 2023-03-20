/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:05:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/20 19:35:40 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	emptystack(t_stack *stack)
{
	if (stack->top == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->next = stack->top;
	if (emptystack(stack))
		stack->bottom = new_node;
	else
		new_node->next->prev = new_node;
	stack->top = new_node;
	return (0);
}

int	push_bottom(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->prev = stack->bottom;
	if (emptystack(stack))
		stack->top = new_node;
	else
		new_node->prev->next = new_node;
	stack->bottom = new_node;
	return (0);
}

int	pop(t_stack *stack)
{
	t_node	*pop_node;
	int		pop_data;

	if (emptystack(stack))
		exit (1);
	pop_node = stack->top;
	stack->top = stack->top->next;
	if (emptystack(stack))
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
		exit (1);
	pop_node = stack->bottom;
	stack->bottom = stack->bottom->prev;
	if (!(stack->bottom))
		stack->top = 0;
	else
		stack->bottom->next = 0;
	pop_data = pop_node->data;
	free(pop_node);
	return (pop_data);
}
