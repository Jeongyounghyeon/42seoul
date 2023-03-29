/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:04:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/29 19:55:14 by youjeong         ###   ########.fr       */
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
			qprms->sorted_arr[i_left + qprms->len_left + qprms->len_mid])
	{
		if (cmd_pb(qprms->stack_a, qprms->stack_b, stack_cmd) == ERROR)
			return (ERROR);
		if ((qprms->stack_b->top->data) < \
			qprms->sorted_arr[i_left + qprms->len_left])
		{
			if (cmd_rb(qprms->stack_b, stack_cmd) == ERROR)
				return (ERROR);
			return (2);
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
	int	rb_cnt;
	int	res_cmd;

	b_cnt = 0;
	r_cnt = 0;
	rb_cnt = 0;
	while (b_cnt < qprms->len_left + qprms->len_mid)
	{
		res_cmd = part_a_cmd(qprms, stack_cmd, i_left);
		if (res_cmd == ERROR)
			return (ERROR);
		if (res_cmd == 1)
			r_cnt++;
		if (res_cmd == 0 || res_cmd == 2)
			b_cnt++;
		if (res_cmd == 2)
			rb_cnt++;
	}
	while (r_cnt--)
		if (cmd_rra(qprms->stack_a, stack_cmd) == ERROR)
			return (ERROR);
	return (rb_cnt);
}

static int	loof_rrb(t_quick_params qprms, t_stack *stack_cmd, int rb_cnt)
{
	while (rb_cnt--)
		if (cmd_rrb(qprms.stack_b, stack_cmd) == ERROR)
			return (ERROR);
	return (0);
}

int	sort_stack_a(t_quick_params qprms, t_stack *stack_cmd, \
				int i_left, int total_len)
{
	int	rb_cnt;

	if (total_len <= 1)
		return (sort_hard_a(qprms, stack_cmd, i_left, total_len));
	update_params(&qprms, total_len);
	rb_cnt = partition_a(&qprms, stack_cmd, i_left);
	if ((rb_cnt == ERROR)
		|| (sort_stack_a(qprms, stack_cmd, \
			i_left + qprms.len_left + qprms.len_mid, qprms.len_right) == ERROR)
		|| (sort_stack_b(qprms, stack_cmd, \
				i_left + qprms.len_left, qprms.len_mid) == ERROR)
		|| (loof_rrb(qprms, stack_cmd, rb_cnt) == ERROR)
		|| (sort_stack_b(qprms, stack_cmd, \
				i_left, qprms.len_left) == ERROR))
		return (ERROR);
	return (0);
}
