/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:17:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 19:52:12 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **argv)
{
	t_stack	*stack_a;
	
	stack_a = make_stack(argv);
	if (!stack_a)
		return (ERROR);
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