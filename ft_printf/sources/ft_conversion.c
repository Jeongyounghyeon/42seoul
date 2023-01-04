/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:34:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/04 20:53:10 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

char	ft_conversion(const char *pfm)
{
	if (*pfm == 0)
		return (0);
	while (*pfm)
	{
		if (isconversion(*pfm))
		{;}
	}
}

int	isconversion(char c)
{
	if (c == '%' || \
		c == 'c' || \
		c == 's' || \
		c == 'd' || \
		c == 'i' || \
		c == 'u' || \
		c == 'p' || \
		c == 'x' || \
		c == 'X')
		return (1);
	return (0);
}

int	isflags(char c)
{
	if (c == '-' || \
		c == '#' || \
		c == ' ' || \
		c == '+' || \
		c == '.' || \
		(c >= '0' && c <= '9'))
		return (1);
	return (0);
}