/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:16:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/04 20:16:07 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef enum e_type {
	command,
	args,
	pipeline,
	redirect,
	word,
	single_quote,
	double_quote,
	null,
}t_type;

typedef struct	s_node {
	char			*word;
	int				type;
	struct s_node	*parent;
	struct s_node	*left;
	struct s_node	*right;
}t_node;

typedef struct	s_tree {
	t_node	*root;
}t_tree;

t_node	*getnode(void);
void	init_tree(t_tree *tree);
void	add_child(t_node *parent, t_node *child, char LR);

#endif