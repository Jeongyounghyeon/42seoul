/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:19:20 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/08 20:10:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		*routine(void *arg_philo);
static int	wait_eating(t_philo *philo, t_info_philo *info_philo);
static int	start_thinking(t_philo *philo, t_info_philo *info_philo);
static int	start_sleeping(t_philo *philo, t_info_philo *info_philo);
int			start_dying(t_philo *philo, t_info_philo *info_philo);

void	*routine(void *arg_philo)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg_philo;
	while (philo->info_philo->flag == 0)
		continue;
	while (1) {
		if (wait_eating(philo, philo->info_philo)
			|| start_sleeping(philo, philo->info_philo)
			|| start_thinking(philo, philo->info_philo))
			break;
	}
	return (0);
}

static int	wait_eating(t_philo *philo, t_info_philo *info_philo)
{
	while (pthread_mutex_lock(philo->lfork) != 0
		|| pthread_mutex_lock(philo->rfork) != 0)
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
	}
	while (pthread_mutex_lock(info_philo->key_print) != 0)
		continue;
	philo->last_eat_time = get_current_time();
	if (info_philo->flag == -1)
		return (1);
	printf("%llu %d has taken a fork\n", get_current_time(), philo->num);
	printf("%llu %d has taken a fork\n", get_current_time(), philo->num);
	printf("%llu %d is eating\n", get_current_time(), philo->num);
	pthread_mutex_unlock(info_philo->key_print);
	usleep(1000 * info_philo->time_to_eat);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (0);
}

static int	start_thinking(t_philo *philo, t_info_philo *info_philo)
{
	while (pthread_mutex_lock(info_philo->key_print) != 0)
		continue;
	if (info_philo->flag == -1)
		return (1);
	printf("%llu %d is thinking\n", get_current_time(), philo->num);
	pthread_mutex_unlock(info_philo->key_print);
	return (0);
}

static int	start_sleeping(t_philo *philo, t_info_philo *info_philo)
{
	while (pthread_mutex_lock(info_philo->key_print) != 0)
		continue;
	if (info_philo->flag == -1)
		return (1);
	printf("%llu %d is sleeping\n", get_current_time(), philo->num);
	pthread_mutex_unlock(info_philo->key_print);
	usleep(info_philo->time_to_sleep * 1000);
	return (0);
}

int	start_dying(t_philo *philo, t_info_philo *info_philo)
{
	while (pthread_mutex_lock(info_philo->key_print) != 0)
		continue;
	if (info_philo->flag == -1)
		return (1);
	printf("%llu %d is dying\n", get_current_time(), philo->num);
	info_philo->flag = -1;
	pthread_mutex_unlock(info_philo->key_print);
	return (0);
}
