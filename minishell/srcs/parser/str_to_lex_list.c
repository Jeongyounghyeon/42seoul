/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_lexer_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:50:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 19:01:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../libft/includes/libft.h"

t_token_list	*str_to_lex_list(const char *str);

t_token_list	*str_to_lex_list(const char *str)
{
	t_token_list	*lst_token;
	t_token_list	*lst_lex;

	lst_token = str_to_token_list(str);
	if (!lst_token)
		return (0);
	lst_lex = token_list_to_lex_list(lst_token);
	free_token_list(lst_token);
	if (!lst_lex)
		return (0);
	// lst_lex = (t_token_list *)malloc(1 * sizeof(t_token_list));
	// if (!lst_lex)
	// {
	// 	free_token_list(lst_token);
	// 	return (0);
	// }
	// init_token_list(lst_lex);
	// if (origin_list_to_cleand_list(lst_token, lst_lex) == -1)
	// {
	// 	free_token_list(lst_lex);
	// 	lst_lex = 0;
	// }
	return (lst_lex);
}
