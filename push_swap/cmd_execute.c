/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:54:40 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/22 16:45:54 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_cmd(char *cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(cmd, "sa", 4) == 0)
		return (execute_sa(stack_a));
	else if (ft_strncmp(cmd, "sb", 4) == 0)
		return (execute_sb(stack_b));
	else if (ft_strncmp(cmd, "ss", 4) == 0)
		return (execute_ss(stack_a, stack_b));
	else if (ft_strncmp(cmd, "pa", 4) == 0)
		return (execute_pa(stack_a, stack_b));
	else if (ft_strncmp(cmd, "pb", 4) == 0)
		return (execute_pb(stack_b, stack_a));
	else if (ft_strncmp(cmd, "ra", 4) == 0)
		return (execute_ra(stack_a));
	else if (ft_strncmp(cmd, "rb", 4) == 0)
		return (execute_rb(stack_b));
	else if (ft_strncmp(cmd, "rr", 4) == 0)
		return (execute_rr(stack_a, stack_b));
	else if (ft_strncmp(cmd, "rra", 4) == 0)
		return (execute_rra(stack_a));
	else if (ft_strncmp(cmd, "rrb", 4) == 0)
		return (execute_rrb(stack_b));
	else if (ft_strncmp(cmd, "rrr", 4) == 0)
		return (execute_rrr(stack_a, stack_b));
	return (ERROR);
}
