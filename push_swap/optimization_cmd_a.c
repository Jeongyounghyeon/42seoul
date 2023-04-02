/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_cmd_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:00:02 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/02 18:50:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimization_cmd_sa(t_stack *stack, t_stack *stack_cmd)
{
	t_node	*pnode;

	pnode = stack_cmd->top;
	if (pnode && pnode->data == ss)
	{
		pop_top(stack_cmd);
		cmd_sb(stack, stack_cmd);
		return (0);
	}
	while (pnode
		&& (pnode->data == rb || pnode->data == rrb
			|| pnode->data == ss || pnode->data == rr || pnode->data == rrr))
		pnode = pnode->next;
	if (pnode && pnode->data == sa)
		rm_node_in_stack(pnode, stack_cmd);
	else if (pnode && pnode->data == sb)
		pnode->data = ss;
	else if (push_top(stack_cmd, sa) == ERROR)
		return (ERROR);
	return (0);
}

int	optimization_cmd_ra(t_stack *stack_cmd)
{
	t_node	*pnode;

	pnode = stack_cmd->top;
	while (pnode && (pnode->data == rr || pnode->data == rrr))
		pnode = pnode->next;
	if (pnode && pnode->data == rb)
	{
		if ((pnode->next && (pnode->next->data == rrr))
			|| (pnode->prev && (pnode->prev->data == rrr)))
		{
			if (pnode->next->data == rrr)
				rm_node_in_stack(pnode->next, stack_cmd);
			else if (pnode->prev->data == rrr)
				rm_node_in_stack(pnode->prev, stack_cmd);
			rm_node_in_stack(pnode, stack_cmd);
		}
		else
			pnode->data = rr;
	}
	else
	{
		if (optimization_cmd_ra_2(pnode, stack_cmd) == ERROR)
			return (ERROR);
	}
	return (0);
}

int	optimization_cmd_rra(t_stack *stack_cmd)
{
	t_node	*pnode;

	pnode = stack_cmd->top;
	while (pnode && (pnode->data == rr || pnode->data == rrr))
		pnode = pnode->next;
	if (pnode && pnode->data == rrb)
	{
		if ((pnode->next && (pnode->next->data == rr))
			|| (pnode->prev && (pnode->prev->data == rr)))
		{
			if (pnode->next->data == rr)
				rm_node_in_stack(pnode->next, stack_cmd);
			else if (pnode->prev->data == rr)
				rm_node_in_stack(pnode->prev, stack_cmd);
			rm_node_in_stack(pnode, stack_cmd);
		}
		else
			pnode->data = rrr;
	}
	else
	{
		if (optimization_cmd_rra_2(pnode, stack_cmd) == ERROR)
			return (ERROR);
	}	
	return (0);
}
