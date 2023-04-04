/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:14:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 11:44:35 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0
# define ERROR -1\

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

typedef struct s_quick_params {
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*sorted_arr;
	int		len_left;
	int		len_mid;
	int		len_right;
}t_quick_params;

int		push_swap(char **argv);
t_stack	*input_to_stack(char **strs_in);
int		show_sorting_stack(t_stack *stack_a, t_stack *stack_b);
int		sort_stack_a(t_quick_params qprms, t_stack *stack_cmd, \
					int i_left, int total_len);
int		sort_stack_b(t_quick_params qprms, t_stack *stack_cmd, \
					int i_left, int total_len);
int		merge_sort(int *arr, int left, int right);

// sort_hard
int		sort_hard_a(t_quick_params qprms, t_stack *stack_cmd, \
				int i_left, int total_len);
int		sort_hard_b(t_quick_params qprms, t_stack *stack_cmd, int total_len);

// cmd
int		cmd_sa(t_stack *stack, t_stack *stack_cmd);
int		cmd_pa(t_stack *stack_b, t_stack *stack_a, t_stack *stack_cmd);
int		cmd_ra(t_stack *stack, t_stack *stack_cmd);
int		cmd_rra(t_stack *stack, t_stack *stack_cmd);
int		cmd_sb(t_stack *stack, t_stack *stack_cmd);
int		cmd_pb(t_stack *stack_a, t_stack *stack_b, t_stack *stack_cmd);
int		cmd_rb(t_stack *stack, t_stack *stack_cmd);
int		cmd_rrb(t_stack *stack, t_stack *stack_cmd);
int		cmd_ss(t_stack *stack_a, t_stack *stack_b, t_stack *stack_cmd);
int		cmd_rr(t_stack *stack_a, t_stack *stack_b, t_stack *stack_cmd);
int		cmd_rrr(t_stack *stack_a, t_stack *stack_b, t_stack *stack_cmd);

// optimization & optimization_cmd
int		check_a_ordered_already(t_quick_params qprms, int total_len);
int		check_b_ordered_already(t_quick_params qprms, t_stack *stack_cmd, \
								int total_len);
int		optimization_cmd_sa(t_stack *stack, t_stack *stack_cmd);
int		optimization_cmd_ra(t_stack *stack_cmd);
int		optimization_cmd_rra(t_stack *stack_cmd);
int		optimization_cmd_sb(t_stack *stack, t_stack *stack_cmd);
int		optimization_cmd_rb(t_stack *stack_cmd);
int		optimization_cmd_rrb(t_stack *stack_cmd);
void	rm_node_in_stack(t_node *node, t_stack *stack);

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
int		*stacktoarr(t_stack *stack);

// free_type
void	free_2p_ch(char **strs);
void	free_stack(t_stack *stack);
void	free_stack_values(t_stack *stack);

// additional files
char	**ft_split_space(char const *s);
int		ft_atoi(const char *str, int *oor);
void	print_cmds(t_stack *stack);

// utils_code
int		loof_rra(t_quick_params *qprms, t_stack *stack_cmd, \
				int r_cnt, int data);
int		optimization_cmd_rb_2(t_node *pnode, t_stack *stack_cmd);
int		optimization_cmd_rrb_2(t_node *pnode, t_stack *stack_cmd);
int		optimization_cmd_ra_2(t_node *pnode, t_stack *stack_cmd);
int		optimization_cmd_rra_2(t_node *pnode, t_stack *stack_cmd);
#endif