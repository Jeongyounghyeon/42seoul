/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:22:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 20:38:54 by youjeong         ###   ########.fr       */
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

typedef struct s_sort_params {
	t_stack	*stack_cmd;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;
	int		left;
	int		pivot1;
	int		pivot2;
	int		right;
}t_sort_params;

int		push_swap(char **argv);
t_stack	*input_to_stack(char **strs_in);
int		show_sorting_stack(t_stack *stack_a, t_stack *stack_b);
int		merge_sort(int *arr, int left, int right);

// execute_cmd
int		execute_cmd_sa(t_stack *stack, t_stack *cmd_res);
int		execute_cmd_pa(t_stack *stack_a, t_stack *stack_b, t_stack *cmd_res);
int		execute_cmd_ra(t_stack *stack, t_stack *cmd_res);
int		execute_cmd_rra(t_stack *stack, t_stack *cmd_res);
int		execute_cmd_sb(t_stack *stack, t_stack *cmd_res);
int		execute_cmd_pb(t_stack *stack_b, t_stack *stack_a, t_stack *cmd_res);
int		execute_cmd_rb(t_stack *stack, t_stack *cmd_res);
int		execute_cmd_rrb(t_stack *stack, t_stack *cmd_res);

// change_type
int		ft_atoi(const char *str);
int		*stacktoarr(t_stack *stack);

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

// free_type
void	free_2p_ch(char **strs);
void	free_stack(t_stack *stack);
void	free_stack_values(t_stack *stack);

// sort_stack
int		sort_stack_a(t_sort_params sprms);
int		sort_hard(t_sort_params prms);

// under_sort_stack
void	print_cmd(t_node *node);
void	set_next_params(t_sort_params *next, t_sort_params pre, int step);

// utils
int		ft_isdigit(int c);
int		ft_isspace(const char c);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*strjoin_sep(char *str0, char *str1, char sep);
int		isrange_int(char *str);

// additional files
char	**ft_split(char const *s, char c);

#endif