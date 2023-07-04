/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:17 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/04 20:16:18 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"

void	init_tree(t_tree *tree);
void	add_child(t_node *parent, t_node *child, char LR);
void	add_parent(t_tree *tree, t_node *parent, t_node *child);

void	init_tree(t_tree *tree)
{	
	tree->root = 0;
}

void	add_child(t_node *parent, t_node *child, char LR)
{
	t_node	*pnode;

	pnode = parent;
	while (LR == 'L' && pnode->left != 0)
		pnode = pnode->left;
	while (LR == 'R' && pnode->right != 0)
		pnode = pnode->right;
	child->parent = pnode;
	if (LR == 'L')
		pnode->left = child;
	else if (LR == 'R')
		pnode->right = child;
}

void	add_parent(t_tree *tree, t_node *parent, t_node *child)
{
	t_node	*pnode;

	pnode = child;
	while (pnode->parent != 0)
		pnode = pnode->parent;
	pnode->left = child;
}