/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_cmd_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:00:02 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/02 18:51:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rm_node_in_stack(t_node *node, t_stack *stack)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (stack->top == node)
		stack->top = node->next;
	if (stack->bottom == node)
		stack->bottom = node->prev;
	free(node);
}

int	optimization_cmd_sb(t_stack *stack, t_stack *stack_cmd)
{
	t_node	*pnode;

	pnode = stack_cmd->top;
	if (pnode && pnode->data == ss)
	{
		pop_top(stack_cmd);
		cmd_sa(stack, stack_cmd);
		return (0);
	}
	while (pnode
		&& (pnode->data == ra || pnode->data == rra
			|| pnode->data == ss || pnode->data == rr || pnode->data == rrr))
		pnode = pnode->next;
	if (pnode && pnode->data == sb)
		rm_node_in_stack(pnode, stack_cmd);
	else if (pnode && pnode->data == sa)
		pnode->data = ss;
	else if (push_top(stack_cmd, sb) == ERROR)
		return (ERROR);
	return (0);
}

int	optimization_cmd_rb(t_stack *stack_cmd)
{
	t_node	*pnode;

	pnode = stack_cmd->top;
	while (pnode && (pnode->data == rr || pnode->data == rrr))
		pnode = pnode->next;
	if (pnode && pnode->data == ra)
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
		if (optimization_cmd_rb_2(pnode, stack_cmd) == ERROR)
			return (ERROR);
	}
	return (0);
}

int	optimization_cmd_rrb(t_stack *stack_cmd)
{
	t_node	*pnode;

	pnode = stack_cmd->top;
	while (pnode && (pnode->data == rr || pnode->data == rrr))
		pnode = pnode->next;
	if (pnode && pnode->data == rra)
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
		if (optimization_cmd_rrb_2(pnode, stack_cmd) == ERROR)
			return (ERROR);
	}
	return (0);
}
