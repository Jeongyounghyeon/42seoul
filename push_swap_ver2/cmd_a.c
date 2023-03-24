/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:29:49 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 10:29:49 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_sa(t_deque *deque)
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

int	cmd_pa(t_deque *deque_a, t_deque *deque_b)
{
	if (emptydeque(deque_b))
		return (0);
	if (push_front(deque_a, pop_front(deque_b)) == ERROR)
		return (ERROR);
	return (0);
}

int	cmd_ra(t_deque *deque)
{
	int	data;

	if (emptydeque(deque) || (deque->front->next == 0))
		return (0);
	data = pop_front(deque);
	return (push_rear(deque, data));
}

int	cmd_rra(t_deque *deque)
{
	int	data;

	if (emptydeque(deque) || (deque->front->next == 0))
		return (0);
	data = pop_rear(deque);
	return (push_front(deque, data));
}
