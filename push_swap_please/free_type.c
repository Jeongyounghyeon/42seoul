/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:30:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 16:50:55 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2p_ch(char **strs)
{
	char	**pstrs;

	if (!strs)
	{
		write(1, "\nfree_2p_ch : you can't free null pointer\n", 42);
		exit(1);
	}
	pstrs = strs;
	while (*pstrs)
	{
		free(*pstrs);
		pstrs++;
	}
	free(strs);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		exit(1);
	while (!emptystack(stack))
		pop_top(stack);
	free (stack);
}

void	free_stack_values(t_stack *stack)
{
	if (!stack)
		exit(1);
	while (!emptystack(stack))
		pop_top(stack);
}
