/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:50:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 19:01:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../libft/includes/libft.h"

t_token_list	*get_token_list(const char *str);
t_token_list	*get_origin_word_list(const char *str);
t_node			*get_first_node_in_str(const char *str);
const char		*get_first_sep_point(const char *str);

t_token_list	*get_token_list(const char *str)
{
	t_token_list	*lst_origin;
	t_token_list	*lst_cleaned;

	lst_origin = get_origin_word_list(str);
	if (!lst_origin)
		reutrn (0);
	lst_cleaned = get_cleaned_list(lst_cleaned);
	return (lst_origin);
}

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
	init_list(lst);
	while (*str)
	{
		while (*str == ' ' && *(str + 1) == ' ')
			str++;
		if (*str == ' ')
			node = get_first_node_in_str(str);
		else
			node = get_first_node_in_str(str);
		if (!node)
		{
			free_list(&lst);
			return (0);
		}
		push_back(lst, node);
		str = str + ft_strlen(node->data->word);
	}
	return (lst);
}

t_node	*get_first_node_in_str(const char *str)
{
	t_node		*node;
	t_token		*token;
	char		*word;
	t_type		type;
	const char	*end_pstr;

	if (*str == '|')
	{
		word = ft_substr(str, 0, 1);
		type = PIPELINE;
	}
	else if (*str == '>' || *str == '<')
	{
		if (ft_strncmp(str, "<<", 2) == 0 
			|| ft_strncmp(str, ">>", 2) == 0)
			word = ft_substr(str, 0, 2);
		else
			word = ft_substr(str, 0, 1);
		type = REDIRECT;
	}
	else if (*str == ' ')
	{
		word = ft_substr(str, 0, 1);
		type = SPACE;
	}
	else
	{
		end_pstr = 0;
		if (*str == '\'' || *str == '\"')
			end_pstr = ft_strchr(str + 1, *str);
		if (end_pstr)
		{
			if (*str == '\'')
				type = SINGLE_QUOTE;
			else
				type = DOUBLE_QUOTE;
		}
		else
		{
			type = WORD;
			end_pstr = get_first_sep_point(str + 1);
			end_pstr--;
		}
		word = ft_substr(str, 0, end_pstr - str + 1);
	}

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

const char	*get_first_sep_point(const char *str)
{
	while (*str
		&& *str != '>' && *str != '<' && *str != '|'
		&& *str != ' ' && *str != '\'' && *str != '\"')
		str++;
	return (str);
}