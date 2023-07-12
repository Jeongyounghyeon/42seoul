/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:30:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/12 14:46:16 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "type.h"

// get_ast_tree
t_tree	*str_to_ast_tree(char *str);

t_token_list	*str_to_lex_list(const char *str);
t_token_list	*str_to_token_list(const char *str);
t_token_list	*token_list_to_lex_list(t_token_list *lst_token);


t_tree	*get_ast_by_list(t_token_list *lst_token);

#endif