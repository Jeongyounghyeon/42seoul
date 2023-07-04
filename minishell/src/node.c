/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/04 20:16:16 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

t_node	*getnode(void);

t_node	*getnode(void)
{
	t_node	*new_node;

	new_node = 0;
	new_node = (t_node *)malloc(1 * sizeof(t_node));
	if (!new_node)
	{
		printf("Not enough memory!");
		return (0);
	}
	new_node->parent = 0;
	new_node->left = 0;
	new_node->right = 0;
	new_node->word = 0;
	new_node->type = 0;
	return (new_node);
}