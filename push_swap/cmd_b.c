/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:46:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 17:14:48 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack *stack)
{
	int	data1;
	int	data2;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data1 = pop(stack);
	data2 = pop(stack);
	if (push(stack, data1) == ERROR)
		return (ERROR);
	if (push(stack, data2) == ERROR)
		return (ERROR);
	return (0);
}

int	pb(t_stack *stack_b, t_stack *stack_a)
{
	if (emptystack(stack_a))
		return (0);
	if (push(stack_b, pop(stack_a)) == ERROR)
		return (ERROR);
	return (0);
}

int	rb(t_stack *stack)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop(stack);
	return (push_bottom(stack, data));
}

int	rrb(t_stack *stack)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop_bottom(stack);
	return (push(stack, data));
}
