/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:17:28 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 21:20:36 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
}t_stack;


t_stack	*make_stack(char **strs_in);
char	**ft_split(char const *s, char c);

// free_type
void	free_char2(char **strs);
void	free_stack(stack *stack);

// stack & stack_func
t_node	*getnode();
void	initstack(t_stack *stack);
int emptystack(t_stack *stack);
int	push(t_stack *stack, int data);
int	push_bottom(t_stack *stack, int data);
int pop(t_stack *stack);
int pop_bottom(t_stack *stack);

// valid
int		isint(char *str);

// utils1
int		ft_isdigit(int c);
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// utils2
char	*strjoin_sep(char *str0, char *str1, char sep);




#endif