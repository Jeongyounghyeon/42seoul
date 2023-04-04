/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:29:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 12:26:22 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_hard_3_case1(t_quick_params qprms, t_stack *stack_cmd, \
							int data[])
{
	if (cmd_ra(qprms.stack_a, stack_cmd) == ERROR)
		return (ERROR);
	if (qprms.stack_a->top->next->next->data != data[0])
	{
		if (cmd_rra(qprms.stack_a, stack_cmd) == ERROR)
			return (ERROR);
		return (1);
	}
	if (data[1] > data[2])
		if (cmd_sa(qprms.stack_a, stack_cmd) == ERROR)
			return (ERROR);
	return (0);
}

static int	sort_hard_3_case3(t_quick_params qprms, t_stack *stack_cmd, \
							int data[])
{
	if (data[0] > data[1])
		if (cmd_sa(qprms.stack_a, stack_cmd) == ERROR)
			return (ERROR);
	return (0);
}

static int	sort_hard_3(t_quick_params qprms, t_stack *stack_cmd)
{
	int	data[3];

	data[0] = qprms.stack_a->top->data;
	data[1] = qprms.stack_a->top->next->data;
	data[2] = qprms.stack_a->top->next->next->data;
	if (data[0] > data[1] && data[0] > data[2])
		return (sort_hard_3_case1(qprms, stack_cmd, data));
	else if (data[1] > data[0] && data[1] > data[2])
		return (1);
	else if (data[0] > data[1])
		return (sort_hard_3_case3(qprms, stack_cmd, data));
	return (0);
}

int	sort_hard_a(t_quick_params qprms, t_stack *stack_cmd, \
				int i_left, int total_len)
{
	if (total_len == 1)
		return (0);
	else if (total_len == 3 && i_left == 0)
		return (sort_hard_3(qprms, stack_cmd));
	return (1);
}
