/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:30:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/09 16:30:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "type.h"

// get_ast_tree
t_tree	*get_ast_tree(char *str);

// get_token_list
t_token_list	*get_token_list(const char *str);
t_token_list	*get_origin_word_list(const char *str);

// get_cleaned_list
int	origin_list_to_cleand_list(t_token_list *origin, t_token_list *cleaned);

#endif