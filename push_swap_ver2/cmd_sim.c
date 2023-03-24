/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:45:59 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 21:26:37 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_ss(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res)
{
	if ((cmd_sa(stack_a, cmd_res) == ERROR) || \
		(cmd_sb(stack_b, cmd_res) == ERROR))
		return (ERROR);
	if (pop_top(cmd_res) || pop_top(cmd_res) || push_top(cmd_res, ss))
		return (ERROR);
	return (0);
}

int	cmd_rr(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res)
{
	if ((cmd_ra(stack_a, cmd_res) == ERROR) || \
		(cmd_rb(stack_b, cmd_res) == ERROR))
		return (ERROR);
	if (pop_top(cmd_res) || pop_top(cmd_res) || push_top(cmd_res, rr))
		return (ERROR);
	return (0);
}

int	cmd_rrr(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res)
{
	if ((cmd_rra(stack_a, cmd_res) == ERROR) || \
		(cmd_rrb(stack_b, cmd_res) == ERROR))
		return (ERROR);
	if (pop_top(cmd_res) || pop_top(cmd_res) || push_top(cmd_res, rrr))
		return (ERROR);
	return (0);
}
