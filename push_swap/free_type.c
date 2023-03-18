/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:58:56 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 20:01:03 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_char2(char **strs)
{
    char    **pstrs;

    if (!strs)
        exit (1);
    pstrs = strs;
    while (!(*pstrs))
    {
        free(*pstrs);
        pstrs++;
    }
    free(strs);
}
void	free_stack(stack *stack)
{
    if (!stack)
        exit (1);
    while (!empty_stack(stack))
        pop(stack);
    free (stack);
}