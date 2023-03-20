/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/20 17:00:37 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	res;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
		else
			sign = 1;
	}	
	while (ft_isdigit(str[i]))
		res = (res * 10) + (str[i++] - '0');
	return (sign * res);
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
