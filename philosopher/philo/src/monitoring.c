/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:51:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/12 20:48:03 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			check_philo(t_philo *philo, t_info_philo *info_philo);
int			start_dying(t_philo *philo, t_info_philo *info_philo);
int			philo_usleep(useconds_t usec, t_philo *philo);

int	check_philo(t_philo *philo, t_info_philo *info_philo)
{
	if (get_current_time() - (philo->last_eat_time) >= (info_philo->time_to_die))
		return (1);
	return (0);
}

int	start_dying(t_philo *philo, t_info_philo *info_philo)
{
	pthread_mutex_lock(&info_philo->key_print);
	if (info_philo->flag == -1)
	{
		pthread_mutex_unlock(&info_philo->key_print);
		return (1);
	}
	printf("%llu %d died\n", get_current_time(), philo->num);
	info_philo->flag = -1;
	pthread_mutex_unlock(&info_philo->key_print);
	return (0);
}

int	philo_usleep(useconds_t usec, t_philo *philo)
{
	t_ms	usec_end;

	usec_end = get_current_time() + (t_ms)(usec / 1000);

	while (get_current_time() < usec_end)
	{
		if (usleep(1000) == ERROR)
			return (ERROR);
		if (check_philo(philo, philo->info_philo) == 1)
		{
			start_dying(philo, philo->info_philo);
			return (1);
		}
	}
	return (0);
}