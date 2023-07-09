/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:20:32 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/08 15:31:14 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/type.h"

void	push_front(t_token_list *lst, t_node *node);
void	push_back(t_token_list *lst, t_node *node);
t_node	*pop_front(t_token_list *lst);
t_node	*pop_back(t_token_list *lst);

void	push_front(t_token_list *lst, t_node *node)
{
	if (isempty_list(lst))
		lst->rear = node;
	else
	{
		node->right = lst->front;
		lst->front->left = node;
	}
	lst->front = node;
}

void	push_back(t_token_list *lst, t_node *node)
{
	if (isempty_list(lst))
		lst->front = node;
	else
	{
		node->left = lst->rear;
		lst->rear->right = node;
	}
	lst->rear = node;
}

t_node	*pop_front(t_token_list *lst)
{
	t_node	*pop_node;

	pop_node = lst->front;
	if (!isempty_list(lst))
	{
		lst->front = pop_node->right;
		if (lst->rear == pop_node)
		{
			lst->front = 0;
			lst->rear = 0;
		}
	}
	return (pop_node);
}

t_node	*pop_back(t_token_list *lst)
{
	t_node	*pop_node;

	pop_node = lst->rear;
	if (!isempty_list(lst))
	{
		lst->rear = pop_node->left;
		if (lst->front == pop_node)
		{
			lst->front = 0;
			lst->rear = 0;
		}
	}
	return (pop_node);
}
