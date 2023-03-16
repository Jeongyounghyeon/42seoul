/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:31:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 21:30:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strarr_join(char **strs_in)
{
	char	*res;
	char	*pstr;
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
	t_stack *stack;
	char	**str_num;
	int		data;
	
	stack = initstack();
	if (!stack)
		return (0);
	str_num = strs;
	while (*str_num)
	{
		if (!isint(str_num) || (push(stack, atoi(str_num)) == ERROR))
		{
			free_stack(stack);
			return (0);
		}
		str_num++;
	}
	return (stack);
}

t_stack	*make_stack(char **strs_in)
{
	t_stack	*stack;
	char	*str_join;
	char	**strs;

	str_join = strarr_join(strs_in);
	free (strs_in);
	if (!str_join)
		return (0);
	strs = ft_split(str_join, ' ');
	free (str_join);
	if (!strs)
		return (0);
	stack = strstostack(strs);
	free (strs);
	return (stack);
}
