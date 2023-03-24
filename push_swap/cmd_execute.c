/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:54:40 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 17:15:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_cmd(char *cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(cmd, "sa", 4) == 0)
		return (sa(stack_a));
	else if (ft_strncmp(cmd, "sb", 4) == 0)
		return (sb(stack_b));
	else if (ft_strncmp(cmd, "ss", 4) == 0)
		return (ss(stack_a, stack_b));
	else if (ft_strncmp(cmd, "pa", 4) == 0)
		return (pa(stack_a, stack_b));
	else if (ft_strncmp(cmd, "pb", 4) == 0)
		return (pb(stack_b, stack_a));
	else if (ft_strncmp(cmd, "ra", 4) == 0)
		return (ra(stack_a));
	else if (ft_strncmp(cmd, "rb", 4) == 0)
		return (rb(stack_b));
	else if (ft_strncmp(cmd, "rr", 4) == 0)
		return (rr(stack_a, stack_b));
	else if (ft_strncmp(cmd, "rra", 4) == 0)
		return (rra(stack_a));
	else if (ft_strncmp(cmd, "rrb", 4) == 0)
		return (rrb(stack_b));
	else if (ft_strncmp(cmd, "rrr", 4) == 0)
		return (rrr(stack_a, stack_b));
	return (ERROR);
}
