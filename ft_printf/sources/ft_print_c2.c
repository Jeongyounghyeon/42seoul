/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:09:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/13 17:09:45 by youjeong         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf.h"
#include "../libft/headers/libft.h"

static int  print_u(va_list ap)
{
    unsigned int     ui;
    char            *str_u;
    int             res;

    ui = va_arg(ap, unsigned int);
    str_u = ft_utoa(ui);
    ft_putstr_fd(str_u, 1);
    res = ft_strlen(str_u);
    free(str_u);
    return (res);
}

static int  print_p(va_list ap)
{
    unsigned int    p;
    char            *str_p;

    p = va_arg(ap, unsigned int);
    str_p = ft_utohex(p, 1);
    ft_putstr_fd("0x", 1);
    ft_putstr_fd(str_p, 1);
    res = ft_strlen("0x") + ft_strlen(str_p);
    free(str_p);
    return (res);
}

static int  print_x(va_list ap)
{
    unsigned int    x;
    char            *str_x;

    x = va_arg(ap, unsigned int);
    str_p = ft_utohex(x, 0);
    ft_putstr_fd(str_x, 1);
    res = ft_strlen(str_p);
    free(str_p);
    return (res);
}

static int  print_X(va_list ap)
{
    unsigned int    X;
    char            *str_x;

    X = va_arg(ap, unsigned int);
    str_p = ft_utohex(X, 1);
    ft_putstr_fd(str_X, 1);
    res = ft_strlen(str_p);
    free(str_p);
    return (res);
}

int ft_print_c2(const char c, va_list ap)
{
    if (c == 'u')
        return (print_u(ap));
    else if (c == 'p')
        return (print_p(ap));
    else if (c == 'x')
        return (print_x(ap));
    else if (c == 'X')
        return (print_X(ap));
    return (0);
}