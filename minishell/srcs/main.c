/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:31:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 19:39:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main()
{
	t_tree	*ast_tree;
	char 	*str;

	str = readline("readline input : ");
	printf("readline output : %s\n", str);
	ast_tree = get_ast_tree(str);
	if (ast_tree)
		free_tree(&ast_tree);
	free(str);
}