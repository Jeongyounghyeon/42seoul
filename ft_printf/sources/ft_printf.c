/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:06:17 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/04 20:22:48 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/printf.h"

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
	unsigned char	tmp;

	pfm = (unsigned char *)format;
	while (pfm)
	{
		if (*pfm == '%')
		{
			tmp = ft_conversion((const char *)(pfm + 1));
			if (!tmp)
				return (0);
			while (*pfm != tmp)
				pfm++;
		}
		else
			ft_putchar_fd(*pfm, 1);
		pfm++;
	}
}
