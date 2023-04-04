/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:29:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 12:19:07 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define TRUE 1
# define FALSE 0
# define ERROR -1\

# include "get_next_line.h"
# include "push_swap.h"

int	checker(char **argv);
int	check_command(t_stack *stack_a, t_stack *stack_b);

int	play_sa(t_stack *stack);
int	play_pa(t_stack *stack_b, t_stack *stack_a);
int	play_ra(t_stack *stack);
int	play_rra(t_stack *stack);
int	play_sb(t_stack *stack);
int	play_pb(t_stack *stack_a, t_stack *stack_b);
int	play_rb(t_stack *stack);
int	play_rrb(t_stack *stack);
int	play_ss(t_stack *stack_a, t_stack *stack_b);
int	play_rr(t_stack *stack_a, t_stack *stack_b);
int	play_rrr(t_stack *stack_a, t_stack *stack_b);

// utils2
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif