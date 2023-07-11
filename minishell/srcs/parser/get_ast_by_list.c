/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ast_by_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:33:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/11 21:39:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_tree	*get_ast_by_list(t_token_list *lst_token);
int	add_node_to_ast_tree(t_tree *ast, t_node *node, t_type pre_type);
int	find_and_add_node_ast_tree(t_tree *tree, t_node *via_node, t_node *node, t_type pre_type);

t_tree	*get_ast_by_list(t_token_list *lst_token)
{
	t_tree	*ast_tree;
	t_node	*pnode;
	int		rtn_func;
	t_type	pre_type;

	ast_tree = (t_tree *)malloc(1 * sizeof(t_tree));
	if (!ast_tree)
	{
		perror("minishell");
		return (0);
	}
	init_tree(ast_tree);
	while (!isempty_token_list(lst_token))
	{
		pnode = pop_front(lst_token);
		rtn_func = add_node_to_ast_tree(ast_tree, pnode, pre_type);
		pre_type = pnode->data->type;
		if (rtn_func == -1)
		{
			// free(pnode);
			// free_tree(ast_tree);
			return (0);
		}
	}
	return (ast_tree);
}

int	add_node_to_ast_tree(t_tree *ast, t_node *node, t_type pre_type)
{
	t_node	*command_node;
	t_token	*command_token;

	if (!ast->root)
	{
		command_token = get_token_with_data(0, COMMAND);
		if (!command_token)
			return (-1);
		command_node = getnode(command_token);
		if (!command_node)
		{
			free_token(command_token);
			return (-1);
		}
		ast->root = command_node;
	}
	if (find_and_add_node_ast_tree(ast, ast->root, node, pre_type) == -1)
		return (-1);
	return (0);
}

int	find_and_add_node_ast_tree(t_tree *tree, t_node *via_node, t_node *node, t_type pre_type)
{
	t_node	*command_node;
	t_token	*command_token;

	if (node->data->type == PIPELINE){
		if (tree->root->data->type == COMMAND)
			printf("%s lparent %s\n", "COMMAND", "PIPELINE");
		else 
			printf("%s lparent %s\n", tree->root->data->word, "PIPELINE");
		add_parent_for_lchild(tree, node, tree->root);
	}
	else
	{
		if (via_node->data->type == PIPELINE)
		{
			if (via_node->right == 0)
			{
				command_token = get_token_with_data(0, COMMAND);
				if (!command_token)
					return (-1);
				command_node = getnode(command_token);
				if (!command_node)
				{
					// free_token(command_token);
					return (-1);
				}
				add_rchild(via_node, command_node);
				printf("%s rchild %s\n", "PIPELINE", "COMMAND");
			}
			find_and_add_node_ast_tree(tree, via_node->right, node, pre_type);
		}
		else
		{
			if (pre_type == REDIRECT || node->data->type == REDIRECT)
			{
				t_node	*pnode = via_node;
				while (pnode->right)
					pnode = pnode->right;
				if (pnode->data->type == COMMAND)
					printf("%s rchild %s\n", "COMMAND", node->data->word);
				else
					printf("%s rchild %s\n", pnode->data->word, node->data->word);
				add_rchild(pnode, node);
			}
			else
			{
				if (!(via_node->left)) {
					printf("%s lchild %s\n", "COMMAND", node->data->word);
					add_lchild(via_node, node);
				}
				else{
					t_node *pnode = via_node->left;
					while (pnode->right)
						pnode = pnode->right;
					add_rchild(pnode, node);
					if (pnode->data->type == COMMAND)
						printf("%s rchild %s\n", "COMMAND", node->data->word);
					else
						printf("%s rchild %s\n", pnode->data->word, node->data->word);
				}
			}
		}
	}
	return (0);
}