/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:43:46 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/21 15:55:11 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ps;

	ps = s + ft_strlen(s);
	while (ps >= s)
	{
		if (*ps == (char)c)
			return ((char *)ps);
		ps--;
	}
	return (0);
}
