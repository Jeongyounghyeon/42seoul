/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:57:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/26 18:11:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	string_cnt(const char *s)
{
	int			str_cnt;
	const char	*p;

	str_cnt = 0;
	p = s;
	while (*p)
	{
		if (ft_isspace(*p))
		{
			while (ft_isspace(*p) && (*p))
				p++;
		}
		else
		{
			while (!ft_isspace(*p) && (*p))
				p++;
			str_cnt++;
		}
	}
	return (str_cnt);
}

static int	mk_strs(char const *s, char **p, int str_cnt)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < str_cnt)
	{
		while (ft_isspace(s[j]) && s[j])
			j++;
		start = j;
		while (!ft_isspace(s[j]) && s[j])
			j++;
		p[i] = ft_substr(s, start, j - start);
		if (p[i] == 0)
		{
			j = 0;
			while (j < i)
				free(p[j++]);
			free(p);
			return (-1);
		}
		i++;
	}
	return (0);
}

char	**ft_split_space(char const *s)
{
	int		str_cnt;
	char	**res;

	str_cnt = string_cnt(s);
	res = (char **)malloc((str_cnt + 1) * sizeof(char *));
	if (res == 0)
		return (0);
	if (mk_strs(s, res, str_cnt) == -1)
		return (0);
	res[str_cnt] = 0;
	return (res);
}
