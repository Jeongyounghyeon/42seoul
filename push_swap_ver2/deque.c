/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:21:41 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 10:21:41 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*getnode(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = 0;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	initdeque(t_deque *deque)
{
	deque->front = 0;
	deque->rear = 0;
	deque->cnt = 0;
}

int	emptydeque(t_deque *deque)
{
	if (deque->cnt == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	isindeque(t_deque *deque, int data)
{
	t_node	*pnode;

	pnode = deque->front;
	while (pnode)
	{
		if (pnode->data == data)
			return (TRUE);
		pnode = pnode->next;
	}
	return (FALSE);
}

