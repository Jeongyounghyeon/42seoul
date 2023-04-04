/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:51:03 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/04 11:43:11 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (str0)
		free(str0);
	return (res);
}

int	*stacktoarr(t_stack *stack)
{
	int		*res;
	int		i;
	t_node	*pnode;

	res = (int *)malloc((len_stack(stack)) * sizeof(int));
	if (!res)
		return (0);
	pnode = stack->top;
	i = 0;
	while (i < (len_stack(stack)))
	{
		res[i++] = pnode->data;
		pnode = pnode->next;
	}
	return (res);
}

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
