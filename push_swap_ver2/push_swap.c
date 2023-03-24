/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:45:30 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 10:45:30 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **argv)
{
	t_deque			*deque_a;
	t_deque			deque_b;

	deque_a = make_deque(argv);
	initdeque(&deque_b);
	if (!deque_a)
		return (ERROR);
	// if (sort_deque(deque_a, &deque_b) == ERROR)
	// 	reutrn (ERROR);
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