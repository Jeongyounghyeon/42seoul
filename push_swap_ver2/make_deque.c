/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:47:19 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 10:47:19 by youjeong         ###   ########seoul.kr  */
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

static t_deque	*strstodeque(char **strs)
{
	t_deque	*deque;
	char	**str_num;
	int		data;

	deque = (t_deque *)malloc(1 * sizeof(deque));
	if (!deque)
		return (0);
	initdeque(deque);
	str_num = strs;
	while (*str_num)
	{
		data = ft_atoi(*str_num);
		if (!isrange_int(*str_num) || isindeque(deque, data))
		{
			free_deque(deque);
			return (0);
		}
		if (push_front(deque, data) == ERROR)
		{
			free_deque(deque);
			return (0);
		}
		str_num++;
	}
	return (deque);
}

t_deque	*make_deque(char **strs_in)
{
	t_deque	*deque;
	char	*str_join;
	char	**strs;

	str_join = strarr_join(strs_in);
	if (!str_join)
		return (0);
	strs = ft_split(str_join, ' ');
	free (str_join);
	if (!strs)
		return (0);
	deque = strstodeque(strs);
	free_char2(strs);
	return (deque);
}
