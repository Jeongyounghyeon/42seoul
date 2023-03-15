/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:31:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 20:22:39 by youjeong         ###   ########.fr       */
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
		{
			free(res);
			return (0);
		}
		pinstr++;
	}
	return (res);
}

static int	*strstoi(char **strs)
{
	int 	*res;
	char	*str_num;
	
	str_num = strs;
	while (str_num)
	{
		// str_num을 int로 바꿔서 res에 넣기
		
		str_num++;
	}

	return (res);
}

static int	*pretreat_strs(char **strs_in)
{
	int		*data_stack;
	char	**strs;
	char	*str_join;

	str_join = strarr_join(strs_in);
	if (!str_join)
		return (0);
	strs = ft_split(str_join, ' ');
	if (!strs)
	{
		free (str_join);
		return (0);
	}
	data_stack = strstoi(strs);
	free (str_join);
	free_char2 (strs);
	return (data_stack);
}

t_stack	*make_stack(char **strs_in)
{
	t_stack	*stack;
	int		*data_stack;

	data_stack = pretreat_strs(strs_in);
	if (!data_stack)
		return (0);
	stack = initstack();
	if (!stack)
	{
		free (data_stack);
		return (0);
	}
	if (push_arr(stack, data_stack) == ERROR)
	{
		free(data_stack);
		free_stack(stack);
		return (0);
	}
	return (stack);
}
