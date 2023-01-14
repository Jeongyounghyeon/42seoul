/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:09:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/14 21:00:55 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	print_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	if (ft_putchar_fd(c, 1) == -1)
		return (-1);
	return (1);
}

static int	print_s(va_list ap)
{
	char	*s;
	int		res;

	s = va_arg(ap, char *);
	if (!s)
	{
		if (ft_putstr_fd("(null)", 1) == -1)
			return (-1);
		res = 6;
	}
	else
	{
		if (ft_putstr_fd(s, 1) == -1)
			return (-1);
		res = ft_strlen(s);
	}
	return (res);
}

static int	print_d(va_list ap)
{
	int		d;
	char	*str_d;
	int		res;

	d = va_arg(ap, int);
	str_d = ft_itoa(d);
	if (str_d == 0)
		return (-1);
	if (ft_putstr_fd(str_d, 1) == -1)
	{
		free (str_d);
		return (-1);
	}
	res = ft_strlen(str_d);
	free(str_d);
	return (res);
}

static int	print_i(va_list ap)
{
	int		i;
	char	*str_i;
	int		res;

	i = va_arg(ap, int);
	str_i = ft_itoa(i);
	if (str_i == 0)
		return (-1);
	if (ft_putstr_fd(str_i, 1) == -1)
	{
		free (str_i);
		return (-1);
	}
	res = ft_strlen(str_i);
	free(str_i);
	return (res);
}

int	ft_print_c1(const char c, va_list ap)
{
	if (c == 'c')
		return (print_c(ap));
	else if (c == 's')
		return (print_s(ap));
	else if (c == 'd')
		return (print_d(ap));
	else if (c == 'i')
		return (print_i(ap));
	return (0);
}
