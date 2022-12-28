/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:51:28 by youjeong          #+#    #+#             */
/*   Updated: 2022/12/28 16:34:34 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	str_cnt(char *str, char charset)
{
	int		str_cnt;
	char	*p;

	str_cnt = 0;
	p = (char *)str;
	while (*p)
	{
		if (*p == charset)
		{
			while ((*p == charset) && (*p))
				p++;
		}
		else
		{
			while ((*p != charset) && (*p))
				p++;
			str_cnt++;
		}
	}
	return (str_cnt);
}

static int	mk_strs(char const *str, char charset, char **p, int str_cnt)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < str_cnt)
	{
		while (str[j] == charset && str[j])
			j++;
		start = j;
		while (str[j] != charset && str[j])
			j++;
		p[i] = ft_substr(str, start, j - start);
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

char	**ft_split(char *str, char *charset)
{
	int		str_cnt;
	char	**res;

	str_cnt = get_strcnt(str, charset);
	res = (char **)malloc((str_cnt + 1) * sizeof(char *));
	if (res == 0)
		return (0);
	if (mk_strs(str, charset, res, str_cnt) == 0)
		return (0);
	res[str_cnt] = 0;
	return (res);
}
