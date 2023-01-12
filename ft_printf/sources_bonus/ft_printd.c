/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:49:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/12 18:19:22 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf_bonus.h"
#include "../libft/headers/libft.h"

static void	print_blank(t_conversion conv, t_dinfo dinfo)
{
	int	prtl;

	prtl = dinfo.lblank;
	if ((conv.wp.precision < 0) && (conv.flag.zero))
		while (prtl-- > 0)
			ft_putchar_fd('0', 1);
	else
		while (prtl-- > 0)
			ft_putchar_fd(' ', 1);
}

static void	print_num(t_dinfo dinfo, t_conversion conv)
{
	int	prtl;

	if (dinfo.lsign)
	{
		if (dinfo.d < 0)
			ft_putchar_fd('-', 1);
		else if (conv.flag.plus == 1)
			ft_putchar_fd('+', 1);
		else if (conv.flag.blank == 1)
			ft_putchar_fd(' ', 1);
	}
	if (conv.flag.zero == 1)
		print_blank(conv, dinfo);
	prtl = dinfo.lpre;
	while (prtl--)
		ft_putchar_fd('0', 1);
	if (dinfo.d < 0)
		ft_putstr_fd((ft_itoa(dinfo.d) + 1), 1);
	else
		ft_putstr_fd(ft_itoa(dinfo.d), 1);
}

void	ft_printd(va_list ap, t_conversion *conv)
{
	t_dinfo	dinfo;

	ft_init("dinfo", &dinfo);
	dinfo.d = va_arg(ap, int);
	dinfo.lnum = ft_strlen(ft_itoa(dinfo.d));
	if (dinfo.d < 0)
		dinfo.lnum--;
	if ((dinfo.d < 0) || (conv->flag.plus) || (conv->flag.blank))
		dinfo.lsign = 1;
	if ((conv->wp.precision >= 0) || (conv->flag.minus))
		conv->flag.zero = 0;
	if (conv->wp.precision > dinfo.lnum)
		dinfo.lpre = conv->wp.precision - dinfo.lnum;
	if (conv->wp.width - (dinfo.lsign + dinfo.lpre + dinfo.lnum) > 0)
		dinfo.lblank = \
			(conv->wp.width) - (dinfo.lsign + dinfo.lpre + dinfo.lnum);
	if (conv->flag.minus)
		print_num(dinfo, *conv);
	if (conv->flag.zero != 1)
		print_blank(*conv, dinfo);
	if (!(conv->flag.minus))
		print_num(dinfo, *conv);
	conv->rescon.length = \
		dinfo.lblank + dinfo.lsign + dinfo.lpre + dinfo.lnum;
	conv->rescon.res = 1;
}
