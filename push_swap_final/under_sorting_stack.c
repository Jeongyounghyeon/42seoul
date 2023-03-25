/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_sorting_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:55:43 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 19:38:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(t_node *node)
{
	if (node->data == sa)
		write(1, "sa\n", 3);
	else if (node->data == pa)
		write(1, "pa\n", 3);
	else if (node->data == ra)
		write(1, "ra\n", 3);
	else if (node->data == rra)
		write(1, "rra\n", 4);
	else if (node->data == sb)
		write(1, "sb\n", 3);
	else if (node->data == pb)
		write(1, "pb\n", 3);
	else if (node->data == rb)
		write(1, "rb\n", 3);
	else if (node->data == rrb)
		write(1, "rrb\n", 4);
	else if (node->data == ss)
		write(1, "ss\n", 3);
	else if (node->data == rr)
		write(1, "rr\n", 3);
	else if (node->data == rrr)
		write(1, "rrr\n", 4);
}

static void	set_params_step_1(t_sort_params *next, t_sort_params pre)
{
	int	lres_stack;

	next->left = pre.pivot2 + 1;
	next->right = pre.right;
	lres_stack = next->right - next->left + 1;
	next->pivot1 = next->left + ((next->right - next->left + 1) / 3);
	next->pivot2 = next->left + (((next->right - next->left + 1) / 3) * 2);
	if (next->pivot2 >= next->right)
		(next->pivot2)--;
}

static void	set_params_step_2(t_sort_params *next, t_sort_params pre)
{
	int	lres_stack;

	next->left = pre.pivot1 + 1;
	next->right = pre.pivot2;
	lres_stack = next->right - next->left + 1;
	next->pivot1 = next->left + (lres_stack / 3) - 1;
	next->pivot2 = next->left + ((lres_stack / 3) * 2) - 1;
	if (next->pivot2 >= next->right)
		(next->pivot2)--;
}

static void	set_params_step_3(t_sort_params *next, t_sort_params pre)
{
	int	lres_stack;

	next->left = pre.left;
	next->right = pre.pivot1;
	lres_stack = next->right - next->left + 1;
	next->pivot1 = next->left + (lres_stack / 3) - 1;
	next->pivot2 = next->left + ((lres_stack / 3) * 2) - 1;
	if (next->pivot2 >= next->right)
		(next->pivot2)--;
}

void	set_next_params(t_sort_params *next, t_sort_params pre, int step)
{
	next->stack_a = pre.stack_a;
	next->stack_b = pre.stack_b;
	next->stack_cmd = pre.stack_cmd;
	next->arr = pre.arr;
	if (step == 1)
		set_params_step_1(next, pre);
	else if (step == 2)
		set_params_step_2(next, pre);
	else if (step == 3)
		set_params_step_3(next, pre);
}
