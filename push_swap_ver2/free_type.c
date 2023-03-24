/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:58:56 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/20 17:01:13 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2p(void **ptr)
{
	char	*pptr;

	if (!ptr)
		return ;
	pptr = ptr;
	while (*pptr)
	{
		free(*pptr);
		pptr++;
	}
	free(pptr);
}

void	free_deque(t_deque *deque)
{
	if (!deque)
		return ;
	while (!emptydeque(deque))
		pop_front(deque);
	free (deque);
}
