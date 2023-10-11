/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:43:15 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 16:41:41 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "xmem.h"

#include "bool.h"

t_bool	is_empty_line(char *line)
{
	char	*empty_signs;
	char	*trimed_line;
	t_bool	value;

	empty_signs = " ";
	value = false;
	trimed_line = xtrim(line, empty_signs);
	if (*trimed_line == '\n')
		value = true;
	free(trimed_line);
	return (value);
}
