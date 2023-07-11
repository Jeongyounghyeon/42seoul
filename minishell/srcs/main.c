/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/11 21:54:47 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void print_preorder(t_node *node);

int main()
{
	t_tree	*ast_tree;
	char 	*str;

	str = readline("readline input : ");
	printf("readline output : %s\n", str);
	ast_tree = get_ast_tree(str);
	if (ast_tree->root)
		printf("root on\n");
	print_preorder(ast_tree->root);
	free(str);
}

void	print_data(t_node	*node)
{
	if (!node)
		return ;
	if (node->data->type == COMMAND)
		printf("COMMAND\n");
	else if (node->data->type == PIPELINE)
		printf("PIPELINE\n");
	else if (node->data->type == REDIRECT)
		printf("REDIRECT %s\n", node->data->word);
	else
		printf("%s\n", node->data->word);
}

void print_preorder(t_node *node)
{
	if (!node)
		return ;
	print_preorder(node->left);
	print_data(node);
	print_preorder(node->right);
}