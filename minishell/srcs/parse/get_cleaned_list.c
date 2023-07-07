/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cleaned_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:46:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 21:12:36 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../libft/includes/libft.h"

t_token_list *get_cleaned_list(t_token_list *origin)
{
	t_node			*node;
	t_token_list	*lst_cleaned;
	t_type			type;

	lst_cleaned = (t_token_list *)malloc(1 * sizeof(t_token_list));
	if (!lst_cleaned)
	{
		perror("minishell");
		return (0);
	}
	while (!isempty_list(origin))
	{
		node = pop_front(origin);
		type = node->data->type;
		// if (type == DOUBLE_QUOTE || type == WORD)
		// 	replace_environment_in_node(node);
		if (type >= SINGLE_QUOTE)
			trim_quote_in_node(node);
	}
}

