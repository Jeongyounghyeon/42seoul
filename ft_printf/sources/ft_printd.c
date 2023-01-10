/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:40:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/07 21:45:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"
#include "../headers/printf.h"

static int	preflag(int num, t_conversion *conv, int *numl)
{
	int	resl = 0;
	if ((conv->flag.plus) || (conv->flag.blank))
	{
		if (num < 0)
		{
			ft_putchar_fd('-', 1);
			numl -= 1;
		}
		else if (conv->flag.plus == 1)
			ft_putchar_fd('+', 1);
		else if (conv->flag.blank == 1)
			ft_putchar_fd(' ', 1);
		resl++;
	}
	return resl;
}

static int	print_num_ver_isprc(int numl, int prflag, t_conversion *conv)
{
	int	resl;

	resl = 0;
	if (conv->wp.precision > numl)
	{
		prtl = (conv->wp.precision) - numl;
		resl += prtl
	}
	else
		prtl = 0;
	while (prtl > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd((str_num + prflag), 1);
	resl += numl;
	return (resl);
}

static int	print_num(int num, t_conversion *conv)
{
	char	*str_num;
	int		numl;
	int		prtl;
	int		prflag;
	int		resl;

	resl = 0;
	str_num = itoa(num);
	numl = ft_strlen(str_num);
	prflag = preflag(num, conv, &numl);
	resl += prflag
	if (conv->wp.precision >= 0)
		resl += print_num_ver_isprc(numl, prflag, conv);
	else
	{
		ft_putstr_fd((str_num + prflag), 1);
		resl += numl;
	}
	free(str_num);
	return (resl);
}

static int	print_blank(t_conversion *conv, int dlen)
{
	int	prtl;
	int resl;

	prtl = (conv->wp.width) - dlen;
	resl = (conv->wp.width) - dlen;
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
	int		d;
	int		dlen;
	int		reslen;

	d = va_arg(ap, int);
	dlen = ft_strlen(ft_itoa(d));
	if ((conv->flag.plus) || (conv->flag.blank))
		dlen++;
	if ((conv->wp.width) > reslen)
		reslen = conv->wp.width;
	if ((conv->wp.precision >= 0) || (conv->flag.minus))
		conv->flag.zero = 0;
	if (conv->flag.plus)
		conv->flag.blank = 0;
	if (conv->flag.minus)
		reslen += print_num(d, conv);
	reslen += print_blank(conv, dlen);
	if (!(conv->flag.minus))
		reslen += print_num(d, conv);
	conv->rescon.length = reslen;
	conv->rescon.res = 1;
}
