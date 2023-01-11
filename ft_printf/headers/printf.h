/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:08:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/11 17:09:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

typedef struct s_flag
{
	int	minus;
	int	zero;
	int	pound;
	int	blank;
	int	plus;
}t_flag;

typedef struct s_wp
{
	int	width;
	int	precision;
}t_wp;

typedef struct s_rescon
{
	int				length;
	int				res;
}t_rescon;

typedef struct s_conversion
{
	t_flag		flag;
	t_wp		wp;
	t_rescon	rescon;
}t_conversion;

typedef struct s_dinfo
{
	int	d;
	int	lpre;
	int	lnum;
	int	lblank;
}t_dinfo;

#endif