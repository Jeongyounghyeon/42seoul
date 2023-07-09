/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cleaned_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:46:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/09 17:08:45 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../libft/includes/libft.h"

int				origin_list_to_cleand_list(t_token_list *origin, t_token_list *cleaned);
static int		move_one_node_interpret(t_token_list *src, t_token_list *dst);
static int		trim_quote_in_node(t_node *node);
static t_node	*merge_double_word_node(t_node *node1, t_node *node2);

int	origin_list_to_cleand_list(t_token_list *origin, t_token_list *cleaned)
{
	while (!isempty_list(origin))
	{		
		if (move_one_node_interpret(origin, cleaned) == -1)
		{
			free_list(cleaned);
			return (-1);
		}
	}
	return (0);
}

static int	move_one_node_interpret(t_token_list *src, t_token_list *dst)
{
	t_node			*node;
	t_type			type;
	static	t_type	pre_type = -1;

	node = pop_front(src);
	type = node->data->type;
	if (type == SPACE)
		free(node);
	else
	{
		if (type == DOUBLE_QUOTE || type == WORD)
		{
			// 환경변수 처리
		}
		if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
			if (trim_quote_in_node(node) == -1)
			{
				free_node(node);
				return (-1);
			}
		type = node->data->type;
		if (type == WORD && pre_type == WORD)
		{
			t_node	*pre_node;
			t_node	*update_node = 0;

			pre_node = pop_back(dst);
			update_node = merge_double_word_node(pre_node, node);
			free_node(pre_node);
			free_node(node);
			if (!update_node)
				return (-1);
			node = update_node;
		}
		push_back(dst, node);
	}
	pre_type = type;
	// if (type == DOUBLE_QUOTE || type == WORD)
	// {
	// 	//환경변수 처리
	// }
	// if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
	// 	if (trim_quote_in_node(node) == -1)
	// 	{
	// 		free_node(node);
	// 		return (-1);
	// 	}
	// type = node->data->type;
	// if (type == WORD && pre_type == WORD)
	// {
	// 	t_node	*pre_node;
	// 	t_node	*update_node = 0;

	// 	pre_node = pop_back(dst);
	// 	update_node = merge_double_word_node(pre_node, node);
	// 	free_node(pre_node);
	// 	free_node(node);
	// 	if (!update_node)
	// 		return (-1);
	// 	node = update_node;
	// }
	// if (type == SPACE)
	// 	free_node(node);
	// else
	// 	push_back(dst, node);
	// pre_type = type;
	return (0);
}

static t_node	*merge_double_word_node(t_node *node1, t_node *node2)
{
	t_node	*new_node;
	t_token	*new_token;
	char	*new_str;

	new_str = ft_strjoin(node1->data->word, node2->data->word);
	new_token = get_token_with_data(new_str, WORD);
	new_node = getnode(new_token);
	if (!new_str || !new_token || !new_node)
	{
		if (new_node)
			free_node(new_node);
		else if (new_token)
			free_token(new_token);
		else if (new_str)
			free(new_str);
		perror("minishell");
		return (0);
	}
	free(new_str);
	return (new_node);
}

static int	trim_quote_in_node(t_node *node)
{
	char	*pre_word;
	char	*update_word;

	pre_word = node->data->word;
	if (*pre_word == '\'')
		update_word = ft_strtrim(pre_word, "\'");
	else
		update_word = ft_strtrim(pre_word, "\"");
	if (!update_word)
	{
		perror("minishell");
		return (-1);
	}
	node->data->word = update_word;
	node->data->type = WORD;
	free(pre_word);
	return (0);
}