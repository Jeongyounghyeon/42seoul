/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:44:50 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 20:09:55 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_hard(t_sort_params prms)
{
	int	cnt_data;

	cnt_data = prms.right - prms.left + 1;
	if (cnt_data == 1)
		return (0);
	else if (cnt_data == 2)
	{
		if ((prms.stack_a->top->data) > (prms.stack_a->top->next->data))
			if (execute_cmd_sa(prms.stack_a, prms.stack_cmd) == ERROR)
				return (ERROR);
		return (0);
	}
	write(1, "sort_hard : out of range cnt_data\n", 34);
	return (0);
}
