/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:30:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 19:33:27 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "type.h"

t_tree	*get_ast_tree(char *str);

// get_token_list
t_token_list	*get_token_list(const char *str);
t_token_list	*get_origin_word_list(const char *str);
t_node			*get_first_node_in_str(const char *str);

#endif