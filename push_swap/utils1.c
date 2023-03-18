/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:37:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 21:09:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

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
