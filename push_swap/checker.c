/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:28:43 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 11:29:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker(char **argv)
{
	t_stack	*stack_a;
	t_stack	stack_b;
	int		res;

	stack_a = input_to_stack(argv);
	if (!stack_a)
		return (ERROR);
	initstack(&stack_b);
	res = check_command(stack_a, &stack_b);
	free_stack(stack_a);
	free_stack_values(&stack_b);
	return (res);
}

int	main(int argc, char **argv)
{
	int	res;

	if (argc == 1)
		return (0);
	res = checker(argv + 1);
	if (res == ERROR)
		write(1, "Error\n", 6);
	if (res == 0)
		write(1, "OK\n", 3);
	if (res == 1)
		write(1, "KO\n", 3);
	return (0);
}
