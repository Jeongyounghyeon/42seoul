/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ast_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:35:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 18:49:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_tree	*get_ast_tree(char *str);

t_tree	*get_ast_tree(char *str)
{
	t_tree			*ast_tree;
	t_token_list	*lst_token;
	
	lst_token = get_token_list(str);
	if (!lst_token)
		return (0);
	// printf("-------------start list---------------\n");
	// while (!isempty_token_list(lst_token))
	// {
	// 	t_token	*token;
	// 	token = lst_token->front->data;
	// 	printf("%d : %s\n", token->type, token->word);
	// 	pop_front(lst_token);
	// }
	// printf("--------------end list--------------\n");
	ast_tree = get_ast_by_list(lst_token);
	return (ast_tree);
	// return (0);
}
