/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:24:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/11 20:05:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/printf.h"

static void	printpc(t_conversion *conv)
{
	int		reslen;

	if (conv->wp.width >= 0)
		reslen = conv->wp.width;
	else
		reslen = 1;
	if (conv->flag.minus == 1)
		ft_putchar_fd('%', 1);
	while ((reslen - 1) > 0)
		ft_putchar_fd(' ', 1);
	conv->rescon.length = reslen;
	conv->rescon.res = 1;
}

void	ft_cv(unsigned char pfm, va_list ap, t_conversion *conv)
{
	if (pfm == '%')
		printpc(&conv);
	else
	{
		if (pfm == 'c')
			ft_printc(ap, &conv);
		else if (pfm == 's')
			ft_prints(ap, &conv);
		else if (pfm == 'd')
			ft_printd(ap, &conv);
		else if (pfm == 'i')
			ft_printi(ap, &conv);
		else if (pfm == 'u')
			ft_printu(ap, &conv);
		else if (pfm == 'x')
			ft_printx(ap, &conv);
		else if (pfm == 'X')
			ft_printX(ap, &conv);
		else if (pfm == 'p')
			ft_printp(ap, &conv);
	}
}
