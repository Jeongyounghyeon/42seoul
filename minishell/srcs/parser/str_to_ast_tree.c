/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_ast_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:35:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 18:49:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_tree	*str_to_ast_tree(char *str);

t_tree	*str_to_ast_tree(char *str)
{
	t_tree			*ast_tree;
	t_token_list	*lst_lex;
	
	lst_lex = str_to_lex_list(str);
	if (!lst_lex)
		return (0);
	// printf("-------------start list---------------\n");
	// while (!isempty_token_list(lst_lex))
	// {
	// 	t_token	*token;
	// 	token = lst_lex->front->data;
	// 	printf("%d : %s\n", token->type, token->word);
	// 	pop_front(lst_lex);
	// }
	// printf("--------------end list--------------\n");
	ast_tree = get_ast_by_list(lst_lex);
	free_token_list(lst_lex);
	return (ast_tree);
}
