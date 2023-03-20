/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:45:59 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/20 19:49:33 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_stack *stack_b, t_stack *stack_a)
{
	if ((sa(stack_a) == ERROR) || (sb(stack_b) == ERROR))
		return (ERROR);
	return (0);
}

int	rr(t_stack *stack_b, t_stack *stack_a)
{
	if ((ra(stack_a) == ERROR) || (rb(stack_b) == ERROR))
		return (ERROR);
	return (0);
}

int	rrr(t_stack *stack_b, t_stack *stack_a)
{
	if ((rra(stack_a) == ERROR) || (rrb(stack_b) == ERROR))
		return (ERROR);
	return (0);
}
