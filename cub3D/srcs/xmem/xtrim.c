/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtrim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:38:24 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 16:39:00 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "xmem.h"

char	*xtrim(const char *s1, const char *set)
{
	size_t	i;

	if (!set || !s1)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]) != 0)
		i--;
	return (xsubstr(s1, 0, i + 1));
}
