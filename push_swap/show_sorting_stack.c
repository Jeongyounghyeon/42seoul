/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_sorting_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:56:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 20:07:22 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*presorted_stack(t_stack *stack)
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

static int	init_sprms(t_sort_params *sprms, t_stack *stack_a, t_stack *stack_b)
{
	int				len_stack_a;

	len_stack_a = len_stack(stack_a);
	sprms->arr = presorted_stack(stack_a);
	if (!sprms->arr)
		return (ERROR);
	sprms->stack_cmd = (t_stack *)malloc(sizeof(t_stack));
	if (!sprms)
		return (ERROR);
	initstack(sprms->stack_cmd);
	sprms->stack_a = stack_a;
	sprms->stack_b = stack_b;
	sprms->left = 0;
	sprms->right = len_stack_a - 1;
	sprms->pivot1 = sprms->left + ((sprms->right - sprms->left + 1) / 3);
	sprms->pivot2 = sprms->left + (((sprms->right - sprms->left + 1) / 3) * 2);
	return (0);
}

static void	print_cmds(t_stack *stack)
{
	t_node	*pnode;

	pnode = stack->bottom;
	while (pnode)
	{
		print_cmd(pnode);
		pnode = pnode->prev;
	}
}

int	show_sorting_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_sort_params	sprms;
	int				len_stack_a;

	if (init_sprms(&sprms, stack_a, stack_b) == ERROR)
	{
		free_stack(sprms.stack_cmd);
		return (ERROR);
	}
	if (sort_stack_a(sprms) == ERROR)
		return (ERROR);
	// 최적화
	print_cmds(sprms.stack_cmd);
	free_stack(sprms.stack_cmd);
	return (0);
}
