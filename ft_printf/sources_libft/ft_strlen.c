/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:01:56 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/07 15:18:49 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlen(const char *s)
{
	int		res;

	res = 0;
	while (*s)
	{
		res++;
		s++;
	}
	return (res);
}
