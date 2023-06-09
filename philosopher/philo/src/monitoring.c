/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:51:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/08 20:09:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*monitoring(void *arg_philo);
static int	check_philo(t_philo *philo, t_info_philo *info_philo);

void	*monitoring(void *arg_philo)
{
	t_philo	*philo;

	philo = (t_philo *)arg_philo;
	while (1) {
		if (check_philo(philo, philo->info_philo)) {
			return (0);
		};
	}
	return (0);
}

static int	check_philo(t_philo *philo, t_info_philo *info_philo)
{
	if (get_current_time() - (philo->last_eat_time) > info_philo->time_to_die) {
		start_dying(philo, info_philo);
		return (1);
	}
	return (0);
}