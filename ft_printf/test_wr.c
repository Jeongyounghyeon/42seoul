#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "headers/printf.h"
#include "libft/libft.h"

static int	preflag(int num, t_conversion *conv, int *numl)
{
	int	resl;

	resl = 0;

	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		(*numl)--;
		resl++;
	}
	else if ((conv->flag.plus) || (conv->flag.blank))
	{
		if (conv->flag.plus == 1)
			ft_putchar_fd('+', 1);
		else if (conv->flag.blank == 1)
			ft_putchar_fd(' ', 1);
		resl++;
	}
	return (resl);
}

static int	prtn_prc(char *str_num, int numl, int prflag, t_conversion *conv)
{
	int	resl;
	int	prtl;

	resl = 0;
	if (conv->wp.precision > numl)
	{
		prtl = (conv->wp.precision) - numl;
		resl += prtl;
	}
	else
		prtl = 0;
	while (prtl-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd((str_num + (ft_strlen(str_num) - numl)), 1);
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
	str_num = ft_itoa(num);
	numl = ft_strlen(str_num);
	prflag = preflag(num, conv, &numl);
	resl += prflag;
	if (conv->wp.precision >= 0)
		resl += prtn_prc(str_num, numl, prflag, conv);
	else
	{
		ft_putstr_fd((str_num + (ft_strlen(str_num) - numl)), 1);
		resl += numl;
	}
	free(str_num);
	return (resl);
}

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

	dinfo.d = va_arg(ap, int);	
	dinfo.lnum = ft_strlen(ft_itoa(dinfo.d));	
	if (dinfo.d < 0)
		dinfo.lnum--;
	if ((dinfo.d < 0) || (conv->flag.plus) || (conv->flag.minus))
		{
		dinfo.lpre = 1;
		if (dinfo.d > 0)
			dinfo.lnum--;
		}
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

int	test_print(char *format, t_conversion *conv, ...)
{
	va_list			ap;

	va_start(ap, conv);
	ft_printd(ap, conv);
	va_end(ap);
	return (0);
}

int main()
{
	t_conversion conv;
	char c;

	conv.flag.minus = 0;
	conv.flag.plus = 0;
	conv.flag.pound = 0;
	conv.flag.zero = 0;
	conv.flag.blank = 1;

	conv.wp.width = 10;
	conv.wp.precision = 7;

	conv.rescon.length = 0;
	conv.rescon.res = 0;

//	printf("%4.s", "abc");
//	test_print("askldjlkasldjk", 'a', 1);
//	test_print("abcdedf", &conv, "abc", "1234","adasd");
//	printf("0\n");

	printf("% 10.7d\n", 12345);
	test_print("I don't know", &conv, 12345);
	printf("\n");
	printf("res = %d\n", conv.rescon.res);
	printf("len = %d\n", conv.rescon.length);
	return 0;
}