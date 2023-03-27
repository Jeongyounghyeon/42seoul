/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:26:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/27 20:35:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_ss(t_stack *stack_a, t_stack *stack_b, t_stack *stack_cmd)
{
	if (cmd_sa(stack_a, stack_cmd) == ERROR
		|| cmd_sb(stack_b, stack_cmd) == ERROR)
		return (ERROR);
	return (0);
}

int	cmd_rr(t_stack *stack_a, t_stack *stack_b, t_stack *stack_cmd)
{
	if (cmd_ra(stack_a, stack_cmd) == ERROR
		|| cmd_rb(stack_b, stack_cmd) == ERROR)
		return (ERROR);
	return (0);
}

int	cmd_rrr(t_stack *stack_a, t_stack *stack_b, t_stack *stack_cmd)
{
	if (cmd_rra(stack_a, stack_cmd) == ERROR
		|| cmd_rrb(stack_b, stack_cmd) == ERROR)
		return (ERROR);
	return (0);
}
