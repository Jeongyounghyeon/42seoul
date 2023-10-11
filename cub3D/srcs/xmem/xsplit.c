/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:36:20 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 16:42:03 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "xmem.h"

size_t	word_length(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	*del_sep(const char *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

int	word_count(const char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		s = del_sep(s, c);
		if (*s && *s != c)
		{
			cnt += 1;
			s += word_length(s, c);
		}
	}
	return (cnt);
}

void	free_all(char **s, int last)
{
	int	i;

	i = 0;
	while (i <= last)
		free (s[i++]);
	free(s);
}

char	**xsplit(const char *s, char c)
{
	char	**split;
	size_t	word_cnt;
	size_t	i;

	word_cnt = word_count(s, c);
	split = (char **)xmalloc(sizeof(char *) * (word_cnt + 1));
	split[word_cnt] = 0;
	i = 0;
	while (i < word_cnt)
	{
		s = del_sep(s, c);
		split[i] = (char *)xmalloc(sizeof(char) * (word_length(s, c) + 1));
		ft_memcpy((void *)split[i], (void *)s, word_length(s, c));
		split[i++][word_length(s, c)] = 0;
		s += word_length(s, c);
	}
	return (split);
}
