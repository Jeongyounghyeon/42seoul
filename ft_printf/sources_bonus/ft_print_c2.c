/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:09:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/14 17:17:45 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static int	print_u(va_list ap)
{
	unsigned int	ui;
	char			*str_u;
	int				res;

	ui = va_arg(ap, unsigned int);
	str_u = ft_utoa(ui);
	ft_putstr_fd(str_u, 1);
	res = ft_strlen(str_u);
	free(str_u);
	return (res);
}

static int	print_p(va_list ap)
{
	size_t	p;
	char	*str_p;
	int		res;

	p = (size_t)va_arg(ap, void *);
	str_p = ft_utop(p);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str_p, 1);
	res = ft_strlen("0x") + ft_strlen(str_p);
	free(str_p);
	return (res);
}

static int	print_x(va_list ap)
{
	unsigned int	x;
	char			*str_x;
	int				res;

	x = va_arg(ap, unsigned int);
	str_x = ft_utohex(x, 0);
	ft_putstr_fd(str_x, 1);
	res = ft_strlen(str_x);
	free(str_x);
	return (res);
}

static int	print_x_up(va_list ap)
{
	unsigned int	x_up;
	char			*str_x_up;
	int				res;

	x_up = va_arg(ap, unsigned int);
	str_x_up = ft_utohex(x_up, 1);
	ft_putstr_fd(str_x_up, 1);
	res = ft_strlen(str_x_up);
	free(str_x_up);
	return (res);
}

int	ft_print_c2(const char c, va_list ap)
{
	if (c == 'u')
		return (print_u(ap));
	else if (c == 'p')
		return (print_p(ap));
	else if (c == 'x')
		return (print_x(ap));
	else if (c == 'X')
		return (print_x_up(ap));
	return (0);
}
