/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:45:59 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/22 16:47:01 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_ss(t_deque *deque_b, t_deque *deque_a)
{
	if ((cmd_sa(deque_a) == ERROR) || (cmd_sb(deque_b) == ERROR))
		return (ERROR);
	return (0);
}

int	cmd_rr(t_deque *deque_b, t_deque *deque_a)
{
	if ((cmd_ra(deque_a) == ERROR) || (cmd_rb(deque_b) == ERROR))
		return (ERROR);
	return (0);
}

int	cmd_rrr(t_deque *deque_b, t_deque *deque_a)
{
	if ((cmd_rra(deque_a) == ERROR) || (cmd_rrb(deque_b) == ERROR))
		return (ERROR);
	return (0);
}