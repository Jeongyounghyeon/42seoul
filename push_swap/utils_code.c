/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:23:13 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/02 18:40:54 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loof_rra(t_quick_params *qprms, t_stack *stack_cmd, int r_cnt, int data)
{
	while (r_cnt-- && (qprms->stack_a->top->data != data))
		if (cmd_rra(qprms->stack_a, stack_cmd) == ERROR)
			return (ERROR);
	return (0);
}

int	optimization_cmd_ra_2(t_node *pnode, t_stack *stack_cmd)
{
	while (pnode \
	&& (pnode->data == sb || pnode->data == rb || pnode->data == rrb))
		pnode = pnode->next;
	if (stack_cmd->top && stack_cmd->top->data == rrr)
		stack_cmd->top->data = rrb;
	else
	{
		while (pnode \
		&& (pnode->data == sb || pnode->data == rb || pnode->data == rrb))
			pnode = pnode->next;
		if (pnode && pnode->data == rra)
			rm_node_in_stack(pnode, stack_cmd);
		else if (push_top(stack_cmd, ra) == ERROR)
			return (ERROR);
	}
	return (0);
}

int	optimization_cmd_rra_2(t_node *pnode, t_stack *stack_cmd)
{
	while (pnode && (pnode->data == rb || pnode->data == rrb))
		pnode = pnode->next;
	if (stack_cmd->top && stack_cmd->top->data == rr)
		stack_cmd->top->data = rb;
	else
	{
		while (pnode \
		&& (pnode->data == sb || pnode->data == rb || pnode->data == rrb))
			pnode = pnode->next;
		if (pnode && pnode->data == ra)
			rm_node_in_stack(pnode, stack_cmd);
		else if (push_top(stack_cmd, rra) == ERROR)
			return (ERROR);
	}
	return (0);
}

int	optimization_cmd_rb_2(t_node *pnode, t_stack *stack_cmd)
{
	while (pnode && (pnode->data == ra || pnode->data == rra))
		pnode = pnode->next;
	if (stack_cmd->top && stack_cmd->top->data == rrr)
		stack_cmd->top->data = rra;
	else
	{
		while (pnode
			&& (pnode->data == sa || pnode->data == ra || pnode->data == rra))
			pnode = pnode->next;
		if (pnode && pnode->data == rrb)
			rm_node_in_stack(pnode, stack_cmd);
		else if (push_top(stack_cmd, rb) == ERROR)
			return (ERROR);
	}
	return (0);
}

int	optimization_cmd_rrb_2(t_node *pnode, t_stack *stack_cmd)
{
	while (pnode && (pnode->data == ra || pnode->data == rra))
			pnode = pnode->next;
	if (stack_cmd->top && stack_cmd->top->data == rr)
		stack_cmd->top->data = ra;
	else
	{
		while (pnode \
			&& (pnode->data == sa || pnode->data == ra || pnode->data == rra))
			pnode = pnode->next;
		if (pnode && pnode->data == rb)
			rm_node_in_stack(pnode, stack_cmd);
		else if (push_top(stack_cmd, rrb) == ERROR)
			return (ERROR);
	}
	return (0);
}
