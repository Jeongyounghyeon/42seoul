/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:31:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/22 17:16:25 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_arr_in_stack(t_stack *stack, int **res)
{
	*res = malloc
}

int	partition(t_sort_params sprms)
{
	return (0);
}

int	sort_stack_a(t_sort_params *sprms)
{
	int	pivot1;
	int	pivot2;
	int	cnt_pb;
	int	cnt_prb;

	//partition(&cnt_pb, &cnt_prb);
	sort_stack_a(sprms);
	while (!cnt_pb--)
		execute_pb(sprms->stack_b, sprms->stack_a);
	sort_stack_a(sprms);
	while (!cnt_prb--)
	{
		execute_rrb(sprms->stack_b);
		execute_pa(sprms->stack_b, sprms->stack_a);
	}
	sort_stack_a(sprms);
	return (0);
}

int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*res;
	int		*pre_sort_arr;

	res = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!res)
		return ERROR;
	return (0);
}