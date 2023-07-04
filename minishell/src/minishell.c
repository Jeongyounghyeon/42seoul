/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/04 20:16:06 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_type	get_type(char **pstr);

int main()
{
	t_tree	lst_input;
	char 	*str = readline("readline input : ");

	printf("%s\n", str);
	// while (*str)
	// {
	// 	// get_type()
	// 	str++;
	// }
}

t_node	*get_token(char **str)
{
	t_node	*token;
	char	*pstr;

	token = 0;
	pstr = *str;
	if (*pstr == 0)
		return (null);
	// malloc error
	if (*pstr == '|')
		token = get_token_by_type(pstr, pipeline);
	else if (*pstr == '>' || *pstr == '<')
	{
		token->type = redirect;
		if (*(pstr + 1) == '>' || *(pstr + 1) == '<')
			

	}
	else if (*pstr == '\'' || *pstr == '\"')
	{
		// qstr = pstr;
		// while (*(++qstr))
		// {
		// 	if (*pstr == *qstr)
		// 		re
		// }
	}
}

char	*get_word_by_token(char *str, t_type type)
{
	t_node	*token;
	char	*pchr;

	token = getnode();
	if (!token)
		return (0);
	token->type = type;
	if (type == pipeline)
		token->word = ft_substr(str, 0, 1);
	else if (type == redirect)
	{
		if (ft_strncmp(str, "<<", 2) == 0 || ft_strncmp(str, ">>", 2) == 0)
			token->word = ft_substr(str, 0, 2);
		else
			token->word = ft_substr(str, 0, 1);
	}
	else if (type == single_quote)
	{
		pchr = ft_strchr(str, '\'');
		if (pchr)
			token->word = ft_substr(str, 1, pchr - str - 1);
		else
		{
			token->type = word;
		}
	}
}