/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:23:39 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/20 19:35:52 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*getnode(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = 0;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

void	initstack(t_stack *stack)
{
	stack->top = 0;
	stack->bottom = 0;
}
