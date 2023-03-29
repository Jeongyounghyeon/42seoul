/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:57:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/27 16:58:24 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmd(t_node *node)
{
	if (node->data == sa)
		write(1, "sa\n", 3);
	else if (node->data == pa)
		write(1, "pa\n", 3);
	else if (node->data == ra)
		write(1, "ra\n", 3);
	else if (node->data == rra)
		write(1, "rra\n", 4);
	else if (node->data == sb)
		write(1, "sb\n", 3);
	else if (node->data == pb)
		write(1, "pb\n", 3);
	else if (node->data == rb)
		write(1, "rb\n", 3);
	else if (node->data == rrb)
		write(1, "rrb\n", 4);
	else if (node->data == ss)
		write(1, "ss\n", 3);
	else if (node->data == rr)
		write(1, "rr\n", 3);
	else if (node->data == rrr)
		write(1, "rrr\n", 4);
}

void	print_cmds(t_stack *stack)
{
	t_node	*pnode;

	pnode = stack->bottom;
	while (pnode)
	{
		print_cmd(pnode);
		pnode = pnode->prev;
	}
}
