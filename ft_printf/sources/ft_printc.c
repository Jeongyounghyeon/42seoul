/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:20:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/11 20:05:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/printf.h"

void	ft_printc(va_list ap, t_conversion *conv)
{
	char	c;
	int		reslen;
	int		prtl;

	if (conv->wp.width >= 0)
		reslen = conv->wp.width;
	else
		reslen = 1;
	c = (char)va_arg(ap, int);
	if (conv->flag.minus == 1)
		ft_putchar_fd(c, 1);
	prtl = reslen;
	while ((reslen - 1) > 0)
	{
		ft_putchar_fd(' ', 1);
		prtl;
	}
	if (conv->flag.minus == 0)
		ft_putchar_fd(c, 1);
	conv->rescon.length = reslen;
	conv->rescon.res = 1;
}