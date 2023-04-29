/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:09:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/21 15:52:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = 0;
	tmp = (void *)malloc(count * size);
	if (tmp == 0)
		return (0);
	else
		ft_bzero(tmp, count * size);
	return (tmp);
}
