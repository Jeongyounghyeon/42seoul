/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:37:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 20:10:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (*str++)
		res++;
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (!dst || !src)
		return (0);
	while ((i < srcsize) && (i + 1 < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
	return (srcsize);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	size;

	size = ft_strlen(s1);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (res == 0)
		return (0);
	ft_strlcpy(res, s1, size + 1);
	return (res);
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
	if (str0)
		while (*str0)
			*pres++ = *str0++;
	if ((str_len[0] > 0) && (str_len[1] > 0))
		*pres++ = sep;
	if (str1)
		while (*str1)
			*pres++ = *str1++;
	*pres = 0;
	return (res);
}
