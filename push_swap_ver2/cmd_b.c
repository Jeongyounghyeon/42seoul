/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:33:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 22:26:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_sb(t_stack *stack, t_stack *cmd_res)
{
	int	data1;
	int	data2;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data1 = pop_top(stack);
	data2 = pop_top(stack);
	if (push_top(stack, data1) == ERROR)
		return (ERROR);
	if (push_top(stack, data2) == ERROR)
		return (ERROR);
	if (push_top(cmd_res, sb))
		return (ERROR);
	return (0);
}

int	cmd_pb(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res)
{
	if (emptystack(stack_b))
		return (0);
	if (push_top(stack_a, pop_top(stack_b)) == ERROR)
		return (ERROR);
	if (push_top(cmd_res, pb))
		return (ERROR);
	return (0);
}

int	cmd_rb(t_stack *stack, t_stack *cmd_res)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop_top(stack);
	if (push_bottom(stack, data))
		return (ERROR);
	if (push_top(cmd_res, rb))
		return (ERROR);
	return (0);
}

int	cmd_rrb(t_stack *stack, t_stack *cmd_res)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop_bottom(stack);
	if (push_top(stack, data))
		return (ERROR);
	if (push_top(cmd_res, rrb))
		return (ERROR);
	return (push_top(stack, data));
}
