/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:06:17 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/12 18:19:25 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf_bonus.h"
#include "../libft/headers/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	print_fm(format, ap);
	va_end(ap);
	return (0);
}

static void	print_fm(const char *format, va_list ap)
{
	unsigned char	*pfm;
	t_rescon		res_con;

	pfm = (unsigned char *)format;
	while (pfm)
	{
		if (*pfm == '%')
		{
			pfm = ft_conversion((const char *)(pfm + 1), &ap, res_con);
		}
		else
			ft_putchar_fd(*pfm, 1);
		pfm++;
	}
}
