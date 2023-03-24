/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:58:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 22:32:39 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	division(t_sprms sprms, int *res_division)
{
	int		b_cnt;
	t_node	*pnode;

	b_cnt = 0;
	while (b_cnt < (sprms.pivot2 - sprms.left + 1))
	{
		pnode = sprms.stack_a->top;
		if (pnode->data <= (sprms.arr)[sprms.pivot1])
		{
			if (cmd_pa(sprms.stack_a, sprms.stack_b, sprms.stack_cmd) == ERROR)
				return (ERROR);
			if (cmd_rb(sprms.stack_b, sprms.stack_cmd) == ERROR)
				return (ERROR);
			res_division[0]++;
			b_cnt++;
		}
		else if (pnode->data <= (sprms.arr)[sprms.pivot2])
		{
			if (cmd_pa(sprms.stack_a, sprms.stack_b, sprms.stack_cmd) == ERROR)
				return (ERROR);
			res_division[1]++;
			b_cnt++;
		}
		else if (cmd_ra(sprms.stack_a, sprms.stack_cmd) == ERROR)
			return (ERROR);
	}
	return (0);
}

static void	set_params(t_sprms *next, t_sprms *pre, int step)
{
	next->stack_a = pre->stack_a;
	next->stack_b = pre->stack_b;
	next->arr = pre->arr;
	if (step == 1)
	{
		next->left = pre->pivot2;
		next->right = pre->right;
		next->pivot1 = pre->pivot2 + (pre->right - pre->pivot2) / 3;
		next->pivot2 = pre->pivot2 + (pre->right - pre->pivot2) / 3 * 2;
	}
	else if (step == 2)
	{
		next->left = pre->pivot1;
		next->right = pre->pivot2;
		next->pivot1 = pre->pivot1 + (pre->pivot2 - pre->pivot1) / 3;
		next->pivot2 = pre->pivot1 + (pre->pivot2 - pre->pivot1) / 3 * 2;
	}
	else if (step == 3)
	{
		next->left = pre->left;
		next->right = pre->pivot1;
		next->pivot1 = pre->left + (pre->pivot1 - pre->left) / 3;
		next->pivot2 = pre->left + (pre->pivot1 - pre->left) / 3 * 2;
	}
}

static int	sort_stack_a(t_sprms sprms, t_stack *stack_cmd)
{
	t_sprms	next_prms;
	int		res_division[2];

	if (sprms.left == sprms.right)
		return (0);
	res_division[0] = 0;
	res_division[1] = 0;
	division(sprms, res_division);
	set_params(&next_prms, &sprms, 1);
	if (sort_stack_a(next_prms, stack_cmd) == ERROR)
		return (ERROR);
	set_params(&next_prms, &sprms, 2);
	if (sort_stack_a(next_prms, stack_cmd) == ERROR)
		return (ERROR);
	set_params(&next_prms, &sprms, 3);
	if (sort_stack_a(next_prms, stack_cmd) == ERROR)
		return (ERROR);
	return (0);
}

int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		*sorted_arr;
	t_stack	stack_cmd;
	t_sprms	sprms;
	int		len_stack_a;

	len_stack_a = len_stack(stack_a);
	sorted_arr = stacktoarr(stack_a);
	if (!sorted_arr)
		return (ERROR);
	if (merge_sort(sorted_arr, 0, len_stack_a - 1) == ERROR)
		return (ERROR);
	initstack(&stack_cmd);
	sprms.stack_a = stack_a;
	sprms.stack_b = stack_b;
	sprms.left = 0;
	sprms.right = len_stack_a - 1;
	sprms.pivot1 = len_stack_a / 3;
	sprms.pivot2 = len_stack_a / 3 * 2;
	sprms.arr = sorted_arr;
	sprms.stack_cmd = &stack_cmd;
	if (sort_stack_a(sprms, &stack_cmd) == ERROR)
		return (ERROR);
	// 최적화
	print_cmds(sprms.stack_cmd);
	free(sorted_arr);
	return (0);
}
