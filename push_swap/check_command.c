/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:24:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 12:18:07 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_valid_cmd(char *str)
{
	if (ft_strncmp(str, "sa\n", 4) == 0)
		return (sa);
	if (ft_strncmp(str, "sb\n", 4) == 0)
		return (sb);
	if (ft_strncmp(str, "ss\n", 4) == 0)
		return (ss);
	if (ft_strncmp(str, "pa\n", 4) == 0)
		return (pa);
	if (ft_strncmp(str, "pb\n", 4) == 0)
		return (pb);
	if (ft_strncmp(str, "ra\n", 4) == 0)
		return (ra);
	if (ft_strncmp(str, "rb\n", 4) == 0)
		return (rb);
	if (ft_strncmp(str, "rr\n", 4) == 0)
		return (rr);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		return (rra);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (rrb);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (rrr);
	return (-1);
}

void	play_cmd(t_stack *stack_a, t_stack *stack_b, int valid)
{
	if (valid == sa)
		play_sa(stack_a);
	if (valid == sb)
		play_sb(stack_b);
	if (valid == ss)
		play_ss(stack_a, stack_b);
	if (valid == pa)
		play_pa(stack_b, stack_a);
	if (valid == pb)
		play_pb(stack_a, stack_b);
	if (valid == ra)
		play_ra(stack_a);
	if (valid == rb)
		play_rb(stack_b);
	if (valid == rr)
		play_rr(stack_a, stack_b);
	if (valid == rra)
		play_rra(stack_a);
	if (valid == rrb)
		play_rrb(stack_b);
	if (valid == rrr)
		play_rrr(stack_a, stack_b);
}

static int	check_ordered(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pnode;
	t_node	*qnode;

	if (stack_b->top)
		return (0);
	pnode = stack_a->top;
	qnode = stack_a->top;
	while (pnode)
	{
		if (qnode->data > pnode->data)
			return (0);
		qnode = pnode;
		pnode = pnode->next;
	}
	return (1);
}

int	check_command(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;
	int		valid;

	str = get_next_line(0);
	if (!str)
	{
		if (!check_ordered(stack_a, stack_b))
			return (1);
		return (0);
	}
	str[ft_strlen(str)] = 0;
	while (str)
	{
		valid = check_valid_cmd(str);
		free(str);
		if (valid == ERROR)
			return (ERROR);
		play_cmd(stack_a, stack_b, valid);
		str = get_next_line(0);
	}
	if (!check_ordered(stack_a, stack_b))
		return (1);
	return (0);
}
