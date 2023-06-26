/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:54:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/26 21:09:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating_routine_1(t_philo *philo, t_info_philo *info_philo)
{
	pthread_mutex_lock(philo->rfork);
	if (print_philo_state(FORMAT_TAKE, philo, info_philo))
	{
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	if (philo_usleep(1000 * info_philo->time_to_die, philo))
	{
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	return (1);
}
