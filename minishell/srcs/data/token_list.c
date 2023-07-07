/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:54:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 19:30:52 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/type.h"

void	init_list(t_token_list *lst);
bool	isempty_list(t_token_list *lst);
void	free_list(t_token_list **lst);

void	init_list(t_token_list *lst)
{
	lst->front = 0;
	lst->rear = 0;
}

bool	isempty_list(t_token_list *lst)
{
	if (lst->front == 0)
		return (true);
	else
		return (false);
}

void	free_list(t_token_list **lst)
{
	while (!isempty_list(*lst))
		free_node(pop_front(*lst));
	free(*lst);
}
