/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ast_by_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:33:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/09 17:15:22 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_tree	*get_ast_by_list(lst_token)
{
	t_tree	*ast_tree;

	ast_tree = (t_tree *)malloc(1 * sizeof(t_tree));
	if (!ast_tree)
	{
		perror("minishell");
		return (0);
	}
	
}