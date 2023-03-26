/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:20:39 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/26 19:13:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*strstostack(char **strs)
{
	t_stack	*stack;
	char	**str_num;
	int		data;
	int		oor;

	stack = (t_stack *)malloc(1 * sizeof(stack));
	if (!stack)
		return (0);
	initstack(stack);
	str_num = strs;
	while (*str_num)
	{
		data = ft_atoi(*str_num, &oor);
		if (oor == -1 || isinstack(stack, data)
			|| push_bottom(stack, data) == ERROR)
		{
			free_stack(stack);
			return (0);
		}
		str_num++;
	}
	return (stack);
}

static char	*strsjoin_sep(char **strs_in, char sep)
{
	char	*joined_str;
	char	**pinstr;

	if (!strs_in)
		return (0);
	joined_str = 0;
	pinstr = strs_in;
	while (*pinstr)
	{
		joined_str = strjoin_sep(joined_str, *pinstr, sep);
		if (!joined_str)
			return (0);
		pinstr++;
	}
	return (joined_str);
}

t_stack	*input_to_stack(char **strs_in)
{
	t_stack	*stack;
	char	*joined_str;
	char	**strs;

	joined_str = strsjoin_sep(strs_in, ' ');
	if (!joined_str)
		return (0);
	strs = ft_split_space(joined_str);
	free (joined_str);
	if (!strs)
		return (0);
	stack = strstostack(strs);
	free_2p_ch(strs);
	return (stack);
}
