/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:45:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/12 18:19:32 by youjeong         ###   ########.fr       */
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

static int	print_addr(t_pinfo pinfo, t_conversion *conv)
{
	unsigned char		str_p[17];
	int					i;
	int					prtl;

	i = 16;
	str_p[i--] = 0;
	ft_putstr_fd("0x", 1);
	while (i >= 0)
	{
		str_p[i--] = "0123456789abcdef"[pinfo.p % 16];
		int_p /= 16;
	}
	i = 0;
	while (str_p[i] == '0')
		i++;
	if ((conv->wp.precision - (16 - i + 1)) > 0)
	{
		prtl = conv->wp.precision - (16 - i + 1);
		while (prtl-- > 0)
			ft_putchar_fd('0', 1);
	}
	else
		conv->wp.precision = 0;
	ft_putstr_fd((char *)str_p + i, 1);
	return (conv->wp.precision + (16 - i));
}

void	ft_printp(va_list ap, t_conversion *conv)
{
	t_pinfo	pinfo;
	int		i;

	pinfo.p = (unsigned long long)va_arg(ap, void *);
	print_addr(pinfo, conv);
	conv->rescon.res = 1;
	conv->rescon.length = 14 - i;
}
