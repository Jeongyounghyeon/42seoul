/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:51:28 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/21 15:54:37 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	string_cnt(const char *s, char c)
{
	int		str_cnt;
	char	*p;

	str_cnt = 0;
	p = (char *)s;
	while (*p)
	{
		if (*p == c)
		{
			while ((*p == c) && (*p))
				p++;
		}
		else
		{
			while ((*p != c) && (*p))
				p++;
			str_cnt++;
		}
	}
	return (str_cnt);
}

static int	mk_strs(char const *s, char c, char **p, int str_cnt)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < str_cnt)
	{
		while ((s[j] == c) && s[j])
			j++;
		start = j;
		while ((s[j] != c) && s[j])
			j++;
		p[i] = ft_substr(s, start, j - start);
		if (p[i] == 0)
		{
			j = 0;
			while (j < i)
				free(p[j++]);
			free(p);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		str_cnt;
	char	**res;

	str_cnt = string_cnt(s, c);
	res = (char **)malloc((str_cnt + 1) * sizeof(char *));
	if (res == 0)
		return (0);
	if (mk_strs(s, c, res, str_cnt) == 0)
		return (0);
	res[str_cnt] = 0;
	return (res);
}
