/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:25:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 10:25:09 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_front(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = getnode();
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->next = deque->front;
	if (emptydeque(deque))
		deque->rear = new_node;
	else
		new_node->next->prev = new_node;
	deque->front = new_node;
	(deque->cnt)++;
	return (0);
}

int	push_rear(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = getnode();
	if (!new_node)
		return (ERROR);
	new_node->data = data;
	new_node->prev = deque->rear;
	if (emptydeque(deque))
		deque->front = new_node;
	else
		new_node->prev->next = new_node;
	deque->rear = new_node;
	(deque->cnt)++;
	return (0);
}

int	pop_front(t_deque *deque)
{
	t_node	*pop_node;
	int		pop_data;

	if (emptydeque(deque))
		exit (1);
	pop_node = deque->front;
	deque->front = deque->front->next;
	(deque->cnt)--;
	if (emptydeque(deque))
		deque->rear = 0;
	else
		deque->front->prev = 0;
	pop_data = pop_node->data;
	free(pop_node);
	return (pop_data);
}

int	pop_rear(t_deque *deque)
{
	t_node	*pop_node;
	int		pop_data;

	if (emptydeque(deque))
		exit (1);
	pop_node = deque->rear;
	deque->rear = deque->rear->prev;
	(deque->cnt)--;
	if (emptydeque(deque))
		deque->front = 0;
	else
		deque->rear->next = 0;
	pop_data = pop_node->data;
	free(pop_node);
	return (pop_data);
}
