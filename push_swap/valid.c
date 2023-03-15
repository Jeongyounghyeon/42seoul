/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:45:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/03/15 21:19:52 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isint(char *str)
{
	char	*absol_value;

	if (!str)
		return (ERROR);
	absol_value = "2147483647";
	if (*str == '-')
	{
		absol_value = "2147483648";
		str++;
	}
	while (*str)
		if (!ft_isdigit(*str) || (*str++ > *absol_value++))
			return (FALSE);
	if (*str)
		return (FALSE);
	return (TRUE);
}