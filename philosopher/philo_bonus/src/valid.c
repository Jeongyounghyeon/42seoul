/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:45:40 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/20 17:02:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			valid_input(char **argv, int argc);
static int	valid_input_common(const char *argv);

int	valid_input(char **argv, int argc)
{
	int	i;

	if (!(argc >= 5 && argc <= 6))
		return (FALSE);
	i = 0;
	while (++i < argc)
	{
		if (!valid_input_common(argv[i]))
			return (FALSE);
	}
	i = 1;
	if (ft_atoi(argv[i]) <= 1)
		return (FALSE);
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (FALSE);
	}
	return (TRUE);
}

static int	valid_input_common(const char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && !(*str == '+'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
