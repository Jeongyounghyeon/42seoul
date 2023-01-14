/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:13:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/12 18:19:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf_bonus.h"
#include "../libft/headers/libft.h"

static void	print_blank(t_conversion conv, t_uinfo uinfo)
{
	int	prtl;

	prtl = uinfo.lblank;
	if ((conv.wp.precision < 0) && (conv.flag.zero))
		while (prtl-- > 0)
			ft_putchar_fd('0', 1);
	else
		while (prtl-- > 0)
			ft_putchar_fd(' ', 1);
}

static void	print_num(t_uinfo uinfo, t_conversion conv)
{
	int	prtl;

	if (conv.flag.zero == 1)
		print_blank(conv, uinfo);
	prtl = uinfo.lpre;
	while (prtl--)
		ft_putchar_fd('0', 1);
	if (uinfo.u < 0)
		ft_putstr_fd((ft_utoa(uinfo.u) + 1), 1);
	else
		ft_putstr_fd(ft_utoa(uinfo.u), 1);
}

void	ft_printu(va_list ap, t_conversion *conv)
{
	t_uinfo	uinfo;

	ft_init("uinfo", &uinfo);
	uinfo.u = va_arg(ap, unsigned int);
	uinfo.lnum = ft_strlen(ft_utoa(uinfo.u));
	if ((conv->wp.precision >= 0) || (conv->flag.minus))
		conv->flag.zero = 0;
	if (conv->wp.precision > uinfo.lnum)
		uinfo.lpre = conv->wp.precision - uinfo.lnum;
	if (conv->wp.width - (uinfo.lpre + uinfo.lnum) > 0)
		uinfo.lblank = \
			(conv->wp.width) - (uinfo.lpre + uinfo.lnum);
	if (conv->flag.minus)
		print_num(uinfo, *conv);
	if (conv->flag.zero != 1)
		print_blank(*conv, uinfo);
	if (!(conv->flag.minus))
		print_num(uinfo, *conv);
	conv->rescon.length = \
		uinfo.lblank + uinfo.lpre + uinfo.lnum;
	conv->rescon.res = 1;
}
