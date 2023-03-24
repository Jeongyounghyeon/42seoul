/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:58:56 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 17:22:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2p_ch(char **strs)
{
	char	**pstrs;

	if (!strs)
		exit(1);
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
