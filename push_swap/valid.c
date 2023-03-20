/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:45:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/20 16:59:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isint(char *str)
{
	char	*absol_value;
	int		len_str;
	int		len_absol;

	if (!str)
		return (ERROR);
	absol_value = "2147483647";
	if (*str == '-')
	{
		absol_value = "2147483648";
		str++;
	}
	len_str = ft_strlen(str);
	len_absol = ft_strlen(absol_value);
	if (len_str < len_absol)
	{
		while (*str)
			if (!ft_isdigit(*str++))
				return (FALSE);
	}
	else if (len_str > len_absol)
		return (FALSE);
	else
		while (*str)
			if (!ft_isdigit(*str) || (*str++ > *absol_value++))
				return (FALSE);
	return (TRUE);
}