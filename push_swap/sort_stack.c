/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:38:37 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 20:28:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	division_1(t_sort_params sprms, int *res_division, int *b_cnt)
{
	if (execute_cmd_pb(sprms.stack_b, sprms.stack_a, sprms.stack_cmd) \
		== ERROR)
		return (ERROR);
	if (execute_cmd_rb(sprms.stack_b, sprms.stack_cmd) == ERROR)
		return (ERROR);
	(*res_division)++;
	(*b_cnt)++;
	return (0);
}

static int	division_2(t_sort_params sprms, int *res_division, int *b_cnt)
{
	if (execute_cmd_pb(sprms.stack_b, sprms.stack_a, sprms.stack_cmd) \
		== ERROR)
		return (ERROR);
	(*res_division)++;
	(*b_cnt)++;
	return (0);
}

static int	division(t_sort_params sprms, int *res_division)
{
	int		b_cnt;
	t_node	*pnode;

	b_cnt = 0;
	res_division[0] = 0;
	res_division[1] = 0;
	while (b_cnt <= (sprms.pivot2 - sprms.left))
	{
		pnode = sprms.stack_a->top;
		if (pnode->data <= sprms.arr[sprms.pivot1])
		{
			if (division_1(sprms, res_division, &b_cnt) == ERROR)
				return (ERROR);
		}
		else if (pnode->data <= sprms.arr[sprms.pivot2])
		{
			if (division_2(sprms, (res_division + 1), &b_cnt) == ERROR)
				return (ERROR);
		}
		else if (execute_cmd_ra(sprms.stack_a, sprms.stack_cmd) == ERROR)
			return (ERROR);
	}
	return (0);
}

static int	comback_stack_a(t_sort_params sprms, int cmd, int cnt)
{
	if (cmd == pa)
	{
		while (cnt--)
			if (execute_cmd_pa(sprms.stack_a, sprms.stack_b, \
				sprms.stack_cmd) == ERROR)
				return (ERROR);
	}
	else if (cmd == rrb)
	{
		while (cnt--)
		{
			if (execute_cmd_rrb(sprms.stack_b, sprms.stack_cmd) == ERROR)
				return (ERROR);
			if (execute_cmd_pa(sprms.stack_a, sprms.stack_b, \
				sprms.stack_cmd) == ERROR)
				return (ERROR);
		}
	}
	else
	{
		write(1, "\ncomback_stack_a : Not valid cmd\n", 33);
		exit(1);
	}
	return (0);
}

int	sort_stack_a(t_sort_params sprms)
{
	t_sort_params	next_sprms;
	int				res_division[2];

	if (sprms.right - sprms.left < 2)
		return (sort_hard(sprms));
	if (division(sprms, res_division) == ERROR)
		return (ERROR);
	set_next_params(&next_sprms, sprms, 1);
	if (sort_stack_a(next_sprms) == ERROR)
		return (ERROR);
	comback_stack_a(sprms, pa, res_division[0]);
	set_next_params(&next_sprms, sprms, 2);
	if (sort_stack_a(next_sprms) == ERROR)
		return (ERROR);
	comback_stack_a(sprms, rrb, res_division[1]);
	set_next_params(&next_sprms, sprms, 3);
	if (sort_stack_a(next_sprms) == ERROR)
		return (ERROR);
	return (0);
}
