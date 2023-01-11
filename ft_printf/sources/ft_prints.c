/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:49:42 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/11 20:05:54 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/printf.h"

static void	lputchar(char *s, int prtl)
{
	while (prtl-- > 0)
		ft_putchar_fd(*s++, 1);
}

void	ft_prints(va_list ap, t_conversion *conv)
{
	char	*s;
	int		slen;
	int		reslen;
	int		prtl;

	s = (char *)va_arg(ap, int *);
	slen = ft_strlen((char *)s);
	if (conv->wp.width >= 0)
		reslen = conv->wp.width;
	else
		reslen = slen;
	if ((conv->wp.precision >= 0) && (conv->wp.precision < slen))
		slen = conv->wp.precision;
	if (conv->flag.minus == 1)
		lputchar(s, slen);
	prtl = reslen - slen;
	while (prtl-- > 0)
		ft_putchar_fd(' ', 1);
	if (conv->flag.minus != 1)
		lputchar(s, slen);
	conv->rescon.length = reslen;
	conv->rescon.res = 1;
}