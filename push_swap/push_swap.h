/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:17:28 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/20 19:50:00 by youjeong         ###   ########.fr       */
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
void	free_stack(t_stack *stack);

// stack & stack_func
t_node	*getnode(void);
void	initstack(t_stack *stack);
int		emptystack(t_stack *stack);
int		push(t_stack *stack, int data);
int		push_bottom(t_stack *stack, int data);
int		pop(t_stack *stack);
int		pop_bottom(t_stack *stack);
int		isinstack(t_stack *stack, int data);

// cmd
int		sa(t_stack *stack);
int		pa(t_stack *stack_a, t_stack *stack_b);
int		ra(t_stack *stack);
int		rra(t_stack *stack);
int		sb(t_stack *stack);
int		pb(t_stack *stack_b, t_stack *stack_a);
int		rb(t_stack *stack);
int		rrb(t_stack *stack);
int		ss(t_stack *stack_b, t_stack *stack_a);
int		rr(t_stack *stack_b, t_stack *stack_a);
int		rrr(t_stack *stack_b, t_stack *stack_a);

// valid
int		isint(char *str);

// utils1
int		ft_isdigit(int c);
int		ft_isspace(const char c);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

// utils2
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*strjoin_sep(char *str0, char *str1, char sep);

#endif
