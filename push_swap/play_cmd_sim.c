/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_cmd_sim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:03:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 12:09:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	play_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (play_sa(stack_a) == ERROR
		|| play_sb(stack_b) == ERROR)
		return (ERROR);
	return (0);
}

int	play_rr(t_stack *stack_a, t_stack *stack_b)
{
	if (play_ra(stack_a) == ERROR
		|| play_rb(stack_b) == ERROR)
		return (ERROR);
	return (0);
}

int	play_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (play_rra(stack_a) == ERROR
		|| play_rrb(stack_b) == ERROR)
		return (ERROR);
	return (0);
}
