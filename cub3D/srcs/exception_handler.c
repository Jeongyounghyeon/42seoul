/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:44:37 by jy_23             #+#    #+#             */
/*   Updated: 2023/10/05 15:55:38 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "exception.h"

void		exception_handler(t_errno errno);
static char	*ft_strerror(t_errno errno);

void	exception_handler(t_errno errno)
{
	char	*err_msg;

	err_msg = ft_strerror(errno);
	if (!err_msg)
	{
		printf("Error\n");
	}
	else
		printf("Error: %s\n", err_msg);
	exit(errno);
}

static char	*ft_strerror(t_errno errno)
{
	if (errno == err_arg)
		return ("Invalid argument");
	else if (errno == err_cub_file)
		return ("Invalid file");
	else if (errno == err_ele_id)
		return ("Invalid element");
	else if (errno == err_ele_info_img)
		return ("Invalid image path");
	else if (errno == err_ele_info_rgb)
		return ("Invalid RGB values");
	else if (errno == err_map)
		return ("Invalid Map");
	else if (errno == err_wall)
		return ("Map is not closed");
	else if (errno == err_player)
		return ("There is no player");
	else if (errno == err_general)
		return ("Fatal: sys-call or mlx");
	else
		return (0);
}
