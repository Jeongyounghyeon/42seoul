/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:25:37 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/02 18:49:23 by youjeong         ###   ########.fr       */
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

static int	part_b_cmd(t_quick_params *qprms, t_stack *stack_cmd, int i_left)
{
	if ((qprms->stack_b->top->data) >= \
			qprms->sorted_arr[i_left + qprms->len_left])
	{
		if (cmd_pa(qprms->stack_b, qprms->stack_a, stack_cmd) == ERROR)
			return (ERROR);
		if ((qprms->stack_a->top->data) < \
		qprms->sorted_arr[i_left + qprms->len_left + qprms->len_mid])
		{
			if (cmd_ra(qprms->stack_a, stack_cmd) == ERROR)
				return (ERROR);
			return (2);
		}
	}
	else
	{
		if (cmd_rb(qprms->stack_b, stack_cmd) == ERROR)
			return (ERROR);
		return (1);
	}
	return (0);
}

static int	partition_b(t_quick_params *qprms, t_stack *stack_cmd, int i_left, \
						int *r_cnt)
{
	int	a_cnt;
	int	ra_cnt;
	int	res_cmd;

	a_cnt = 0;
	*r_cnt = 0;
	ra_cnt = 0;
	while (a_cnt < qprms->len_mid + qprms->len_right)
	{
		res_cmd = part_b_cmd(qprms, stack_cmd, i_left);
		if (res_cmd == ERROR)
			return (ERROR);
		if (res_cmd == 1)
			(*r_cnt)++;
		if (res_cmd == 0 || res_cmd == 2)
			a_cnt++;
		if (res_cmd == 2)
			ra_cnt++;
	}
	return (ra_cnt);
}

static int	loof_rr(t_quick_params qprms, t_stack *stack_cmd, int ra_cnt, \
					int r_cnt)
{
	while (r_cnt && ra_cnt)
	{
		if (cmd_rrr(qprms.stack_a, qprms.stack_b, stack_cmd) == ERROR)
			return (ERROR);
		r_cnt--;
		ra_cnt--;
	}
	while (ra_cnt--)
		if (cmd_rra(qprms.stack_a, stack_cmd) == ERROR)
			return (ERROR);
	while (r_cnt--)
		if (cmd_rrb(qprms.stack_b, stack_cmd) == ERROR)
			return (ERROR);
	return (0);
}

int	sort_stack_b(t_quick_params qprms, t_stack *stack_cmd, \
				int i_left, int total_len)
{
	int	ra_cnt;
	int	r_cnt;

	if (check_b_ordered_already(qprms, stack_cmd, total_len))
		return (0);
	if (total_len <= 1)
		return (sort_hard_b(qprms, stack_cmd, total_len));
	update_params(&qprms, total_len);
	ra_cnt = partition_b(&qprms, stack_cmd, i_left, &r_cnt);
	if ((ra_cnt == ERROR)
		|| (sort_stack_a(qprms, stack_cmd, \
			i_left + qprms.len_left + qprms.len_mid, qprms.len_right) == ERROR)
		|| (loof_rr(qprms, stack_cmd, ra_cnt, r_cnt) == ERROR)
		|| (sort_stack_a(qprms, stack_cmd, \
			i_left + qprms.len_left, qprms.len_mid) == ERROR)
		|| (sort_stack_b(qprms, stack_cmd, \
			i_left, qprms.len_left) == ERROR))
		return (ERROR);
	return (0);
}
