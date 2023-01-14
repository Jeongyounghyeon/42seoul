/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:47:29 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/12 18:19:16 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/printf_bonus.h"
#include "../libft/headers/libft.h"

static int	init_conversion(t_conversion *conv)
{
	conv->flag.minus = 0;
	conv->flag.zero = 0;
	conv->flag.plus = 0;
	conv->flag.blank = 0;
	conv->flag.plus = 0;
	conv->wp.width = -1;
	conv->wp.precision = -1;
	conv->rescon.length = 0;
	conv->rescon.res = 0;
	return (1);
}

static int	init_dinfo(t_dinfo *dinfo)
{
	dinfo->d = 0;
	dinfo->lsign = 0;
	dinfo->lpre = 0;
	dinfo->lnum = 0;
	dinfo->lblank = 0;
	return (1);
}

static int	init_uinfo(t_uinfo *uinfo)
{
	uinfo->u = 0;
	uinfo->lpre = 0;
	uinfo->lnum = 0;
	uinfo->lblank = 0;
	return (1);
}

static int	init_pinfo(t_pinfo *pinfo)
{
	pinfo->p = 0;
	pinfo->laddr = 0;
	pinfo->lblank = 0;
	pinfo->lpre = 0;
	return (1);
}

int	ft_init(char *type, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, type);
	if (!ft_strncmp(type, "conversion", 11))
		res = init_conversion(va_arg(ap, t_conversion *));
	else if (!ft_strncmp(type, "dinfo", 11))
		res = init_dinfo(va_arg(ap, t_dinfo *));
	else if (!ft_strncmp(type, "uinfo", 11))
		res = init_uinfo(va_arg(ap, t_uinfo *));
	va_end(ap);
	return (res);
}