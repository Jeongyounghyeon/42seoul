/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:28:59 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 17:14:43 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
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

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (emptystack(stack_b))
		return (0);
	if (push(stack_a, pop(stack_b)) == ERROR)
		return (ERROR);
	return (0);
}

int	ra(t_stack *stack)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop(stack);
	return (push_bottom(stack, data));
}

int	rra(t_stack *stack)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop_bottom(stack);
	return (push(stack, data));
}
