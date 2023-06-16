/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:31:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/16 17:33:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_group_of_philo(t_philo *philo)
{
	if (philo->num == philo->info_philo->nbr_of_philos)
		return (3);
	else if (philo->num % 2 == 0)
		return (2);
	else
		return (1);
}
