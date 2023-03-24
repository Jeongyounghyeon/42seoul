/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/24 17:29:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		if ((c1[i] == 0) || (c2[i] == 0))
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sl;

	sub = 0;
	sl = ft_strlen(s);
	if (len > (sl - start))
		len = sl - start;
	if (start > sl)
		return (ft_strdup(""));
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

char	*strjoin_sep(char *str0, char *str1, char sep)
{
	char	*res;
	char	*pres;
	int		resl;
	int		str_len[2];

	res = 0;
	str_len[0] = ft_strlen(str0);
	str_len[1] = ft_strlen(str1);
	resl = str_len[0] + str_len[1];
	if ((str_len[0] > 0) && (str_len[1] > 0))
		resl++;
	res = (char *)malloc((resl + 1) * sizeof(char));
	if (!res)
		return (0);
	pres = res;
	pres = pres + ft_strlcpy(pres, str0, str_len[0] + 1);
	if ((str_len[0] > 0) && (str_len[1] > 0))
		*pres++ = sep;
	pres = pres + ft_strlcpy(pres, str1, str_len[1] + 1);
	*pres = 0;
	return (res);
}

int	isrange_int(char *str)
{
	char	*absol_value;

	if (!str)
		return (ERROR);
	absol_value = "2147483647";
	if (*str == '-')
	{
		absol_value = "2147483648";
		str++;
	}
	if (ft_strlen(str) < ft_strlen(absol_value))
	{
		while (*str)
			if (!ft_isdigit(*str++))
				return (FALSE);
	}
	else if (ft_strlen(str) > ft_strlen(absol_value))
		return (FALSE);
	else
		while (*str)
			if (!ft_isdigit(*str) || (*str++ > *absol_value++))
				return (FALSE);
	return (TRUE);
}
