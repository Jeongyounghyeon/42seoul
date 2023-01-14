/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:03:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/13 16:03:25 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../libft/headers/libft.h"

static int print_conversion(const char **ppf, va_list ap)
{
    (*ppf)++;
    if (**ppf == '%')
    {
        ft_putchar_fd('%', 1);
        return (1);
    }
    else if (**ppf == 'c')
        return (ft_print_c1(**ppf, ap));
    else if (**ppf == 's')
        return (ft_print_c1(**ppf, ap));
    else if (**ppf == 'd')
        return (ft_print_c1(**ppf, ap));
    else if (**ppf == 'i')
        return (ft_print_c1(**ppf, ap));
    else if (**ppf == 'u')
        return (ft_print_c2(**ppf, ap));
    else if (**ppf == 'p')
        return (ft_print_c2(**ppf, ap));
    else if (**ppf == 'x')
        return (ft_print_c2(**ppf, ap));
    else if (**ppf == 'X')
        return (ft_print_c2(**ppf, ap));
    (*ppf)--;
    return (0);
}

static int  print_format(const char *format, va_list ap)
{
    const char  *pf;
    int         res;

    pf = format;
    while (*pf)
    {
        if (*pf == '%')
            res += print_conversion(&pf, ap);
        else
        {
            ft_putchar_fd(*pf, 1);
            res++;
        }
        pf++;
    }
    return (res);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     res;

    va_start(ap, format);
    res = print_format(format, ap);
    va_end(ap);
    return (res);
}