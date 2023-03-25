/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_sim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:00:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 14:16:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_cmd_ss(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res)
{
	if ((execute_cmd_sa(stack_a, cmd_res) == ERROR) || \
		(execute_cmd_sb(stack_b, cmd_res) == ERROR))
		return (ERROR);
	if (pop_top(cmd_res) || pop_top(cmd_res) || push_top(cmd_res, ss))
		return (ERROR);
	return (0);
}

int	execute_cmd_rr(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res)
{
	if ((execute_cmd_ra(stack_a, cmd_res) == ERROR) || \
		(execute_cmd_rb(stack_b, cmd_res) == ERROR))
		return (ERROR);
	if (pop_top(cmd_res) || pop_top(cmd_res) || push_top(cmd_res, rr))
		return (ERROR);
	return (0);
}

int	execute_cmd_rrr(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res)
{
	if ((execute_cmd_rra(stack_a, cmd_res) == ERROR) || \
		(execute_cmd_rrb(stack_b, cmd_res) == ERROR))
		return (ERROR);
	if (pop_top(cmd_res) || pop_top(cmd_res) || push_top(cmd_res, rrr))
		return (ERROR);
	return (0);
}
