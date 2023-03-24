/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:58:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 10:58:03 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static update_cmdarr(t_cmd *cmdarr, t_cmd cmd)
{

}

static int	division(t_sprms sprms)
{
	int		b_cnt;
	t_node	*pnode;

	b_cnt = 0;
	while (b_cnt < (sprms.right - sprms.left) / 3 * 2)
	{
		pnode = sprms.deque_a->front;
		if (pnode->data < (sprms.arr)[sprms.pivot1])
		{
			cmd_pa()
		}
		if (cmd_ra(sprms.deque_a) == ERROR)
			return (ERROR);
		
	}
}

/// @brief 
/// @param next 
/// @param pre 
/// @param step 
static void	set_next_step(t_sprms *next, t_sprms *pre, int step)
{
	next->deque_a = pre->deque_a;
	next->deque_b = pre->deque_b;
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
	write(1, "Exception : Set undefine parameter value (step).\n", 40);
}

static int	sort_deque_a(t_sprms sparms, t_deque *deque_cmd)
{
	t_sprms	next_prms;

	division(sparms);
	set_next_step(&next_prms, &sparms, 1);
	if (sort_deque_a(next_prms, deque_cmd) == ERROR)
		return (ERROR);

	set_next_step(&next_prms, &sparms, 2);
	if (sort_deque_a(next_prms, deque_cmd) == ERROR);
		return (ERROR);

	set_next_step(&next_prms, &sparms, 3);
	if (sort_deque_a(next_prms, deque_cmd) == ERROR);
		return (ERROR);
	return (0);
}

int	sort_deque(t_deque *deque_a, t_deque *deque_b)
{
	int		*sorted_arr;
	t_deque	deque_cmd;
	t_sprms	sparms;

	sorted_arr = dequetoarr(deque_a);
	if (!sorted_arr)
		return (ERROR);
	merge_sort(sorted_arr, 0, (deque_a->cnt) - 1);
	initdeque(&deque_cmd);
	sparms.deque_a = deque_a;
	sparms.deque_b = deque_b;
	sparms.left = 0
	sparms.right = (deque_a->cnt) - 1;
	sparms.pivot1 = (deque_a->cnt) / 3;
	sparms.pivot1 = (deque_a->cnt) / 3 * 2;
	sparms.arr = sorted_arr;
	if (sort_deque_a(sparms, &deque_cmd) == ERROR);
		return (ERROR);
}
