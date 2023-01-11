/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:49:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/11 20:05:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../headers/printf.h"

static int	print_blank(t_conversion *conv, t_dinfo dinfo)
{
	int	prtl;
	int	resl;

	prtl = (conv->wp.width) - (dinfo.lpre + dinfo.lnum);
	resl = prtl;
	if ((conv->wp.precision < 0) && (conv->flag.zero))
		while (prtl-- > 0)
			ft_putchar_fd('0', 1);
	else
		while (prtl-- > 0)
			ft_putchar_fd(' ', 1);
	if (resl > 0)
		return (resl);
	else
		return (0);
}

void	ft_printd(va_list ap, t_conversion *conv)
{
	t_dinfo	dinfo;

	ft_init("dinfo", &dinfo);
	dinfo.d = va_arg(ap, int);	
	dinfo.lnum = ft_strlen(ft_itoa(dinfo.d));	
	
	
	
	if (dinfo.d < 0)
		dinfo.lnum--;
	if ((dinfo.d < 0) || (conv->flag.plus) || (conv->flag.minus))
		dinfo.lpre = 1;
	else 
		dinfo.lpre = 0;
	if (conv->wp.precision > (dinfo.lnum + dinfo.lpre))
		dinfo.lnum = conv->wp.precision;
	if ((conv->wp.precision >= 0) || (conv->flag.minus))
		conv->flag.zero = 0;
	if (conv->flag.plus)
		conv->flag.blank = 0;
	if (conv->flag.minus)
		conv->rescon.length += print_num(dinfo.d, conv);
	conv->rescon.length += print_blank(conv, dinfo);
	if (!(conv->flag.minus))
		conv->rescon.length += print_num(dinfo.d, conv);
	conv->rescon.res = 1;
}