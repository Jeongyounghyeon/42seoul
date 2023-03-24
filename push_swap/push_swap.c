/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:17:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/22 17:11:00 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **argv)
{
	t_stack			*stack_a;
	t_stack			stack_b;
	t_sort_params	*sprms;

	stack_a = make_stack(argv);
	initstack(&stack_b);
	if (!stack_a)
		return (ERROR);
	sprms = (t_sort_params *)malloc(1 * sizeof(t_sort_params));
	if (!sprms)
		return (ERROR);
	initsprms(&sprms);
	sprms->left = stack_a->top->data;
	sprms->right = stack_a->bottom->data;
	sort_stack_a(sprms);
	return (0);
}

int	main(int argc, char **argv)
{
	int	res;

	if (argc == 1)
		return (0);
	res = push_swap(argv + 1);
	if (res == ERROR)
		write(1, "Error\n", 6);
	return (0);
}

void	initsprms(t_sort_params *sprms)
{
	sprms->stack_a = 0;
	sprms->stack_b = 0;
	sprms->pivot1 = 0;
	sprms->pivot2 = 0;
	sprms->left = 0;
	sprms->right = 0;
}
