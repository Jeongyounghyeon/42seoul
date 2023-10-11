/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:57:01 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 16:58:32 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

#include "map.h"
#include "exception.h"

void	valid_extension(char *file)
{
	char	*extension;
	char	*cub_file;

	if (file)
	{
		cub_file = ".cub\0";
		extension = ft_strrchr(file, '.');
		if (!extension
			|| ft_strncmp(extension, cub_file, ft_strlen(cub_file) + 1))
		{
			exception_handler(err_cub_file);
		}
		else
			return ;
	}
	else
	{
		exception_handler(err_arg);
	}
}
