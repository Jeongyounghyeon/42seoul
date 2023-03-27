/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:04:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/27 21:38:25 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_params(t_quick_params *qprms, int total_len)
{
	qprms->len_left = total_len / 3;
	qprms->len_mid = total_len / 3;
	qprms->len_right = total_len / 3;
	if (total_len % 3 > 0)
	{
		(qprms->len_right)++;
		if (total_len % 3 == 2)
			(qprms->len_mid)++;
	}
}

static int	part_a_cmd(t_quick_params *qprms, t_stack *stack_cmd, int i_left)
{
	if ((qprms->stack_a->top->data) < \
			qprms->sorted_arr[i_left + qprms->len_left])
	{
		if (cmd_pb(qprms->stack_a, qprms->stack_a, stack_cmd) == ERROR)
			return (ERROR);
		if ((qprms->stack_a->top->data) < \
			qprms->sorted_arr[i_left + qprms->len_left + qprms->len_mid])
		{
			if (cmd_rb(qprms->stack_b, stack_cmd) == ERROR)
				return (ERROR);
		}
	}
	else
	{
		if (cmd_ra(qprms->stack_a, stack_cmd) == ERROR)
			return (ERROR);
		return (1);
	}
	return (0);
}

static int	partition_a(t_quick_params *qprms, t_stack *stack_cmd, int i_left)
{
	int	b_cnt;
	int	r_cnt;
	int	res_cmd;

	b_cnt = 0;
	r_cnt = 0;
	while (b_cnt < qprms->len_left + qprms->len_mid)
	{
		res_cmd = part_a_cmd(qprms, stack_cmd, i_left);
		if (res_cmd == ERROR)
			return (ERROR);
		else if (res_cmd == 1)
			r_cnt++;
		else
			b_cnt++;
	}
	while (r_cnt--)
		if (cmd_rra(qprms->stack_a, stack_cmd) == ERROR)
			return (ERROR);
	return (0);
}

int	sort_stack_a(t_quick_params qprms, t_stack *stack_cmd, \
				int i_left, int total_len)
{
	if (total_len <= 1)
		return (sort_hard_a(qprms, stack_cmd, i_left, total_len));
	update_params(&qprms, total_len);
	if ((partition_a(&qprms, stack_cmd, i_left) == ERROR)
		|| (sort_stack_a(qprms, stack_cmd, qprms.len_right, \
						i_left + qprms.len_left + qprms.len_mid) == ERROR)
		|| (sort_stack_b(qprms, stack_cmd, qprms.len_mid, \
						i_left + qprms.len_left) == ERROR)
		|| (sort_stack_b(qprms, stack_cmd, qprms.len_left, \
						i_left) == ERROR))
		return (ERROR);
	return (0);
}
