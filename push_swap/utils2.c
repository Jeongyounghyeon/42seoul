/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:09:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 21:10:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
