/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:32:35 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 21:37:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

# include <unistd.h>
# include <stdlib.h>

typedef enum cmd {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr}t_cmd;

typedef struct s_node {
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
}t_stack;

typedef struct s_sprms {
	t_stack	*stack_cmd;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;
	int		pivot1;
	int		pivot2;
	int		left;
	int		right;
}t_sprms;

int		push_swap(char **argv);
t_stack	*make_stack(char **strs_in);
int		sort_stack(t_stack *stack_a, t_stack *stack_b);
void	print_cmds(t_stack *stack);

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

// cmd
int		cmd_sa(t_stack *stack, t_stack *cmd_res);
int		cmd_pa(t_stack *stack_a, t_stack *stack_b, t_stack *cmd_res);
int		cmd_ra(t_stack *stack, t_stack *cmd_res);
int		cmd_rra(t_stack *stack, t_stack *cmd_res);
int		cmd_sb(t_stack *stack, t_stack *cmd_res);
int		cmd_pb(t_stack *stack_a, t_stack *stack_b, t_stack *cmd_res);
int		cmd_rb(t_stack *stack, t_stack *cmd_res);
int		cmd_rrb(t_stack *stack, t_stack *cmd_res);
int		cmd_ss(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res);
int		cmd_rr(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res);
int		cmd_rrr(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res);

// merge_sort
int		merge_sort(int *arr, int left, int right);

// free_type
void	free_2p_ch(char **ptr);
void	free_stack(t_stack *stack);

// change_type
int		ft_atoi(const char *str);
int		*stacktoarr(t_stack *stack);

// utils
int		ft_isdigit(int c);
int		ft_isspace(const char c);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*strjoin_sep(char *str0, char *str1, char sep);
int		isrange_int(char *str);

// additional file
char	**ft_split(char const *s, char c);

#endif