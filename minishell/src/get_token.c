/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:27:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/04 22:02:24 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*get_token(char *str)
{
	t_node	*token;

	token = 0;
	if (*str == 0)
		return (0);
	token = getnode();
	// malloc error
	if (*str == '|')
	{
		token->type = pipeline;
		token->word = ft_substr(str, 0, 1);
	}
	else if (*str == '<' || *str == '>')
	{
		token->type = redirect;
		if (ft_strncmp(str, "<<", 2) == 0 || ft_strncmp(str, ">>", 2) == 0)
			token->word = ft_substr(str, 0, 2);
		else
			token->word = ft_substr(str, 0, 1);
	}
	else if (*str == '\'' || *str == '\"')
	{
		char	*pstr;

		pstr = ft_strchr(str + 1, *str);
		if (pstr)
			token->word = ft_substr(str, 1, pstr - str - 1);
		else
		{
			pstr = str + 1;
		}
	}
}

t_type	get_type_token(char *str)
{
	if (!(*str))
		return (null);
	else if (*str == '|')
		return (pipeline);
	else if (*str == '>' || *str == '<')
		return (redirect);
	else if (*str == '\'' || *str == '\"')
	{
		if (ft_strchr(str + 1, '\''))
			
	}
}