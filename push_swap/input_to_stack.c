/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:20:39 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/25 20:13:42 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strarr_join(char **strs_in)
{
	char	*res;
	char	**pinstr;

	if (!strs_in)
		return (0);
	res = 0;
	pinstr = strs_in;
	while (*pinstr)
	{
		res = strjoin_sep(res, *pinstr, ' ');
		if (!res)
			return (0);
		pinstr++;
	}
	return (res);
}

static t_stack	*strstostack(char **strs)
{
	t_stack	*stack;
	char	**str_num;
	int		data;

	stack = (t_stack *)malloc(1 * sizeof(stack));
	if (!stack)
		return (0);
	initstack(stack);
	str_num = strs;
	while (*str_num)
	{
		data = ft_atoi(*str_num);
		if (!isrange_int(*str_num) || isinstack(stack, data))
		{
			free_stack(stack);
			return (0);
		}
		if (push_bottom(stack, data) == ERROR)
		{
			free_stack(stack);
			return (0);
		}
		str_num++;
	}
	return (stack);
}

t_stack	*input_to_stack(char **strs_in)
{
	t_stack	*stack;
	char	*str_join;
	char	**strs;

	str_join = strarr_join(strs_in);
	if (!str_join)
		return (0);
	strs = ft_split(str_join, ' ');
	free (str_join);
	if (!strs)
		return (0);
	stack = strstostack(strs);
	free_2p_ch(strs);
	return (stack);
}
