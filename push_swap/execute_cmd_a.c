/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:00:41 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 18:20:43 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_cmd_sa(t_stack *stack, t_stack *cmd_res)
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
	if (push_top(cmd_res, sa))
		return (ERROR);
	return (0);
}

int	execute_cmd_pa(t_stack *stack_a, t_stack *stack_b, t_stack *cmd_res)
{
	if (emptystack(stack_b))
	{
		write(1, "\nexecute_cmd_pa : stack_b is empty.\n", 36);
		exit(1);
	}
	if (push_top(stack_a, pop_top(stack_b)) == ERROR)
		return (ERROR);
	if (push_top(cmd_res, pa))
		return (ERROR);
	return (0);
}

int	execute_cmd_ra(t_stack *stack, t_stack *cmd_res)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop_top(stack);
	if (push_bottom(stack, data))
		return (ERROR);
	if (push_top(cmd_res, ra))
		return (ERROR);
	return (0);
}

int	execute_cmd_rra(t_stack *stack, t_stack *cmd_res)
{
	int	data;

	if (emptystack(stack) || (stack->top->next == 0))
		return (0);
	data = pop_bottom(stack);
	if (push_top(stack, data))
		return (ERROR);
	if (push_top(cmd_res, rra))
		return (ERROR);
	return (0);
}
