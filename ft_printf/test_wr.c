#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "headers/printf.h"
#include "headers/libft.h"

static void	lputchar(char *s, size_t prtl)
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
	if ((conv->wp.precision != -1) && (conv->wp.precision < slen))
		slen = conv->wp.precision;
	if (conv->flag.minus == 1)
		lputchar(s, slen);
	if (reslen > slen)
		prtl = reslen - slen;
	while (prtl-- > 0){
		ft_putchar_fd(' ', 1);
	}
	if (conv->flag.minus != 1)
		lputchar(s, slen);
	conv->rescon.length = reslen;
	conv->rescon.res = 1;
}


void	ft_printc(va_list ap, t_conversion *conv)
{
	int		c;
	int		len;

	len = conv->wp.width;
	if (len < 1)
		len = 1;
	else
		len = conv->wp.width;
	c = va_arg(ap, int);
	if (conv->flag.minus == 1)
		write(1, &c, 1);
	while (len - 1)
	{
		write(1, " ", 1);
		len--;
	}
	if (conv->flag.minus == 0)
		write(1, &c, 1);
	conv->rescon.length = len;
	conv->rescon.res = 1;
}

int	test_print(char *format, t_conversion *conv, ...)
{
	va_list			ap;

	va_start(ap, conv);
	ft_prints(ap, conv);
	va_end(ap);
	return (0);
}

int main()
{
	t_conversion conv;
	char c;

	conv.flag.minus = 1;
	conv.flag.plus = 0;
	conv.flag.pound = 0;
	conv.flag.zero = 0;
	conv.flag.blank = 0;

	conv.wp.width = 2;
	conv.wp.precision = -1;

//	printf("%4.s", "abc");
//	test_print("askldjlkasldjk", 'a', 1);
//	test_print("abcdedf", &conv, "abc", "1234","adasd");
//	printf("0\n");
	printf("%2.6d", -32354);
	return 0;
}