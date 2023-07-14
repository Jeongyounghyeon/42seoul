/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:30:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/14 16:01:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "type.h"

// get_ast_tree
void	parse(char *str, t_tree *ast);

t_token_list	*str_to_lex_list(const char *str);
void			tokenize(const char *str, t_token_list *lst_token);
void			lex(t_token_list *lst_token, t_token_list *lst_lex);


void	parse_tree(t_token_list *lst_token, t_tree *ast);

// valid
void	valid_syntax(t_token_list *lst);

#endif