/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_sorting_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:46:37 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/27 21:50:54 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*presort_stack(t_stack *stack)
{
	int	*res;

	res = stacktoarr(stack);
	if (!res)
		return (0);
	if (merge_sort(res, 0, len_stack(stack) - 1) == ERROR)
	{
		free(res);
		return (0);
	}
	return (res);
}

static int	initqprms(t_quick_params *qprms, t_stack *stack_a, t_stack *stack_b)
{
	int	len_stack_a;

	len_stack_a = len_stack(stack_a);
	qprms->sorted_arr = presort_stack(stack_a);
	if (!qprms->sorted_arr)
		return (ERROR);
	qprms->stack_a = stack_a;
	qprms->stack_b = stack_b;
	qprms->len_left = len_stack_a / 3;
	qprms->len_mid = len_stack_a / 3;
	qprms->len_right = len_stack_a / 3;
	if (len_stack_a % 3 > 0)
	{
		(qprms->len_right)++;
		if (len_stack_a % 3 == 2)
			(qprms->len_mid)++;
	}
	return (0);
}

static t_stack	*cmd_sorting_stack(t_quick_params qprms)
{
	t_stack	*stack_cmd;

	stack_cmd = (t_stack *)malloc(1 * sizeof(stack_cmd));
	if (!stack_cmd)
		return (0);
	if (sort_stack_a(qprms, stack_cmd, 0, \
		qprms.len_left + qprms.len_mid + qprms.len_right) == ERROR)
	{
		free_stack(stack_cmd);
		return (0);
	}
	return (stack_cmd);
}

int	show_sorting_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_quick_params	qprms;
	t_stack			*stack_cmd;

	if (initqprms(&qprms, stack_a, stack_b) == ERROR)
		return (ERROR);
	stack_cmd = cmd_sorting_stack(qprms);
	free(qprms.sorted_arr);
	if (!stack_cmd)
		return (-1);
	print_cmds(stack_cmd);
	free_stack(stack_cmd);
	return (0);
}
