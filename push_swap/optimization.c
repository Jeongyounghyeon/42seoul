/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:52:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/02 18:48:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a_ordered_already(t_quick_params qprms, int total_len)
{
	t_node	*pnode;
	t_node	*qnode;
	int		i;

	pnode = qprms.stack_a->top;
	qnode = qprms.stack_a->top;
	i = total_len;
	while (i--)
	{
		if (qnode->data > pnode->data)
			return (0);
		qnode = pnode;
		pnode = pnode->next;
	}
	return (1);
}

int	check_b_ordered_already(t_quick_params qprms, t_stack *stack_cmd, \
							int total_len)
{
	t_node	*pnode;
	t_node	*qnode;
	int		i;

	pnode = qprms.stack_b->top;
	qnode = qprms.stack_b->top;
	i = total_len;
	while (i--)
	{
		if (qnode->data < pnode->data)
			return (0);
		qnode = pnode;
		pnode = pnode->next;
	}
	while (total_len--)
		cmd_pa(qprms.stack_b, qprms.stack_a, stack_cmd);
	return (1);
}
