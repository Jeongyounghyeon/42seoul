/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:29:49 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 22:26:45 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_sa(t_stack *stack, t_stack *cmd_res)
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
	if (push_top(cmd_res, sa))
		return (ERROR);
	return (0);
}

int	cmd_pa(t_stack *stack_a, t_stack *stack_b, t_stack *cmd_res)
{
	if (emptystack(stack_a))
		return (0);
	if (push_top(stack_b, pop_top(stack_a)) == ERROR)
		return (ERROR);
	if (push_top(cmd_res, pa))
		return (ERROR);
	return (0);
}

int	cmd_ra(t_stack *stack, t_stack *cmd_res)
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

int	cmd_rra(t_stack *stack, t_stack *cmd_res)
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
