/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:32:35 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 09:32:35 by youjeong         ###   ########seoul.kr  */
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

typedef struct s_deque {
	t_node	*front;
	t_node	*rear;
	int		cnt;
}t_deque;

typedef struct s_sprms {
	t_deque	*deque_a;
	t_deque	*deque_b;
	int		*arr;
	int		pivot1;
	int		pivot2;
	int		left;
	int		right;
}t_sprms;

int		push_swap(char **argv);
t_deque	*make_deque(char **strs_in);

// deque & deque_func
t_node	*getnode(void);
void	initdeque(t_deque *deque);
int		emptydeque(t_deque *deque);
int		isindeque(t_deque *deque, int data);
int		push_front(t_deque *deque, int data);
int		push_rear(t_deque *deque, int data);
int		pop_front(t_deque *deque);
int		pop_rear(t_deque *deque);

// cmd
int		cmd_sa(t_deque *deque);
int		cmd_pa(t_deque *deque_a, t_deque *deque_b);
int		cmd_ra(t_deque *deque);
int		cmd_rra(t_deque *deque);
int		cmd_sb(t_deque *deque);
int		cmd_pb(t_deque *deque_a, t_deque *deque_b);
int		cmd_rb(t_deque *deque);
int		cmd_rrb(t_deque *deque);
int		cmd_ss(t_deque *deque_b, t_deque *deque_a);
int		cmd_rr(t_deque *deque_b, t_deque *deque_a);
int		cmd_rrr(t_deque *deque_b, t_deque *deque_a);

// merge_sort
void	merge_sort(int *arr, int left, int right);

// free_type
void	free_2p(void **ptr);
void	free_deque(t_deque *deque);

// change_type
int		ft_atoi(const char *str);
int		*dequetoarr(t_deque *deque);

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