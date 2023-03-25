/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:00:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 18:21:00 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_cmd_sb(t_stack *stack, t_stack *cmd_res)
{
	int	data1;
	int	data2;

	if (emptystack(stack) || (stack->top->next == 0))
	{
		write(1, "\nexecute_cmd_sa : stack_a is empty.\n", 36);
		exit(1);
	}
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

int	execute_cmd_pb(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res)
{
	if (emptystack(stack_a))
	{
		write(1, "\nexecute_cmd_pa : stack_a is empty.\n", 36);
		exit(1);
	}
	if (push_top(stack_b, pop_top(stack_a)) == ERROR)
		return (ERROR);
	if (push_top(cmd_res, pb))
		return (ERROR);
	return (0);
}

int	execute_cmd_rb(t_stack *stack, t_stack *cmd_res)
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

int	execute_cmd_rrb(t_stack *stack, t_stack *cmd_res)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop_bottom(stack);
	if (push_top(stack, data))
		return (ERROR);
	if (push_top(cmd_res, rrb))
		return (ERROR);
	return (0);
}
