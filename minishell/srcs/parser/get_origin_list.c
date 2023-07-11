/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_origin_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:39:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/11 21:40:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../libft/includes/libft.h"

t_token_list	*get_origin_word_list(const char *str);
static t_node	*get_first_node_in_str(const char *str);
static t_type	get_first_type_in_str(const char *str);
static char		*get_frist_word_by_type(const char *str, t_type type);
static int		is_parse_sep(char c);

t_token_list	*get_origin_word_list(const char *str)
{
	t_token_list	*lst;
	t_node			*node;

	lst = (t_token_list *)malloc(1 * sizeof(t_token_list));
	if (!lst)
	{
		perror("minishell");
		return (0);
	}
	init_token_list(lst);
	while (*str)
	{
		while (*str == ' ' && *(str + 1) == ' ')
			str++;
		node = get_first_node_in_str(str);
		if (!node)
		{
			free_token_list(lst);
			lst = 0;
			return (0);
		}
		push_back(lst, node);
		str = str + ft_strlen(node->data->word);
	}
	return (lst);
}

static t_node	*get_first_node_in_str(const char *str)
{
	t_node		*node;
	t_token		*token;
	char		*word;
	t_type		type;

	type = get_first_type_in_str(str);
	word = get_frist_word_by_type(str, type);
	if (!word)
		return (0);
	token = get_token_with_data(word, type);
	free(word);
	if (!token)
		return (0);
	node = getnode(token);
	if (!node)
		free(token);
	return (node);
}

static t_type	get_first_type_in_str(const char *str)
{
	if (*str == '|')
		return (PIPELINE);
	else if (*str == '>' || *str == '<')
		return (REDIRECT);
	else if (*str == ' ')
		return (SPACE);
	else if (*str == '\'' && ft_strchr(str + 1, '\''))
		return (SINGLE_QUOTE);
	else if (*str == '\"' && ft_strchr(str + 1, '\"'))
		return (DOUBLE_QUOTE);
	else
		return (WORD);
}

static char	*get_frist_word_by_type(const char *str, t_type type)
{
	char		*word;
	const char	*end_ptr;

	end_ptr = str;
	if (ft_strncmp(str, "<<", 2) == 0
		|| ft_strncmp(str, ">>", 2) == 0)
		word = ft_substr(str, 0, 2);
	else if (type == PIPELINE || type == SPACE || type == REDIRECT)
		word = ft_substr(str, 0, 1);
	else
	{
		if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
			end_ptr = ft_strchr(str + 1, *str);
		else
		{
			while (!is_parse_sep(*str))
				end_ptr++;
		}
		word = ft_substr(str, 0, end_ptr - str + 1);
	}
	if (!word)
		perror("minishell");
	return (word);
}

static int	is_parse_sep(char c)
{
	if (c == 0
		|| c == '>' || c == '<' || c == '|'
		|| c != ' ' || c == '\'' || c == '\"')
		return (true);
	return (false);
}
