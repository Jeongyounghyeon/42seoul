/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:14:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/26 19:00:40 by youjeong         ###   ########.fr       */
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

int		push_swap(char **argv);
t_stack	*input_to_stack(char **strs_in);

// stack & stack_func
t_node	*getnode(void);
void	initstack(t_stack *stack);
int		emptystack(t_stack *stack);
int		isinstack(t_stack *stack, int data);
int		len_stack(t_stack *stack);

int		push_top(t_stack *stack, int data);
int		push_bottom(t_stack *stack, int data);
int		pop_top(t_stack *stack);
int		pop_bottom(t_stack *stack);

// utils1
int		ft_isdigit(int c);
int		ft_isspace(const char c);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

// utils2
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*strjoin_sep(char *str0, char *str1, char sep);

// free_type
void	free_2p_ch(char **strs);
void	free_stack(t_stack *stack);
void	free_stack_values(t_stack *stack);

// additional files
char	**ft_split_space(char const *s);
int		ft_atoi(const char *str, int *oor);

#endif