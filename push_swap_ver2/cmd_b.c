/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:33:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 10:33:44 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_sb(t_deque *deque)
{
	int	data1;
	int	data2;

	if (emptydeque(deque) || (deque->front->next == 0))
		return (0);
	data1 = pop_front(deque);
	data2 = pop_front(deque);
	if (push_front(deque, data1) == ERROR)
		return (ERROR);
	if (push_front(deque, data2) == ERROR)
		return (ERROR);
	return (0);
}

int	cmd_pb(t_deque *deque_b, t_deque *deque_a)
{
	if (emptydeque(deque_b))
		return (0);
	if (push_front(deque_b, pop_front(deque_a)) == ERROR)
		return (ERROR);
	return (0);
}

int	cmd_rb(t_deque *deque)
{
	int	data;

	if (emptydeque(deque) || (deque->front->next == 0))
		return (0);
	data = pop_front(deque);
	return (push_rear(deque, data));
}

int	cmd_rrb(t_deque *deque)
{
	int	data;

	if (emptydeque(deque) || (deque->front->next == 0))
		return (0);
	data = pop_rear(deque);
	return (push_front(deque, data));
}
