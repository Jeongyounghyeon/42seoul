/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:20:56 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/21 15:54:43 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
