/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:34:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/07 13:11:17 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"

unsigned char	*ft_conversion(const char *pfm, va_list *ap, t_rescon *res_con)
{
	t_flag		flags;
	t_wp	wp;

	if (*pfm == 0)
	{
		res_con->length = 0;
		res_con->res = 0;
		return (pfm);
	}
	while (*pfm)
	{
		if (isconversion(*pfm))
			ft_cv(*pfm, ap, flags, wp, res_con);
		else if (isflags(*pfm))
			;
		else
			pfm++;
	}
	return (pfm - 1);
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
