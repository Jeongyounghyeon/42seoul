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
static int	wait_eating_odd(t_philo *philo, t_info_philo *info_philo);
static int	wait_eating_even(t_philo *philo, t_info_philo *info_philo);
static int	start_thinking(t_philo *philo, t_info_philo *info_philo);
static int	start_sleeping(t_philo *philo, t_info_philo *info_philo);

void	*routine(void *arg_philo)
{
	t_philo	*philo;
	int		(*eating_routin)(t_philo *, t_info_philo *);
	
	philo = (t_philo *)arg_philo;
	if (philo->num % 2 != 0)
		eating_routin = wait_eating_odd;
	else
		eating_routin = wait_eating_even;
	while(1)
	{
		pthread_mutex_lock(&philo->info_philo->flag_mutex);
		if (philo->info_philo->flag == 1)
		{
			pthread_mutex_unlock(&philo->info_philo->flag_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->info_philo->flag_mutex);
	}
	while (philo->info_philo->flag == 0)
	philo->last_eat_time = get_current_time();
	if (philo->num % 2 == 0)
	{
		if (philo_usleep(1000 * philo->info_philo->time_to_eat, philo) == 1)
			return (0);
	}
	while (1) {
		if (eating_routin(philo, philo->info_philo)
			|| start_sleeping(philo, philo->info_philo)
			|| start_thinking(philo, philo->info_philo))
			break;
	}
	return (0);
}

static int	wait_eating_odd(t_philo *philo, t_info_philo *info_philo)
{
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_lock(&info_philo->key_print);
	philo->last_eat_time = get_current_time();
	// necessary edit
	if (check_philo(philo, info_philo) || info_philo->flag == -1)
	{
		pthread_mutex_unlock(&info_philo->key_print);
		start_dying(philo, info_philo);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	printf("%llu %d has taken a fork\n", get_current_time(), philo->num);
	printf("%llu %d has taken a fork\n", get_current_time(), philo->num);
	printf("%llu %d is eating\n", get_current_time(), philo->num);
	pthread_mutex_unlock(&info_philo->key_print);
	if (philo_usleep(1000 * info_philo->time_to_eat, philo) == 1)
		return (1);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (0);
}


static int	wait_eating_even(t_philo *philo, t_info_philo *info_philo)
{
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(&info_philo->key_print);
	philo->last_eat_time = get_current_time();
	if (check_philo(philo, info_philo) || info_philo->flag == -1)
	{
		pthread_mutex_unlock(&info_philo->key_print);
		start_dying(philo, info_philo);
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	printf("%llu %d has taken a fork\n", get_current_time(), philo->num);
	printf("%llu %d has taken a fork\n", get_current_time(), philo->num);
	printf("%llu %d is eating\n", get_current_time(), philo->num);
	pthread_mutex_unlock(&info_philo->key_print);
	if (philo_usleep(1000 * info_philo->time_to_eat, philo) == 1)
		return (1);
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	return (0);
}

static int	start_thinking(t_philo *philo, t_info_philo *info_philo)
{
	pthread_mutex_lock(&info_philo->key_print);
	if (check_philo(philo, info_philo) || info_philo->flag == -1)
	{
		pthread_mutex_unlock(&info_philo->key_print);
		start_dying(philo, info_philo);
		return (1);
	}
	printf("%llu %d is thinking\n", get_current_time(), philo->num);
	pthread_mutex_unlock(&info_philo->key_print);
	return (0);
}

static int	start_sleeping(t_philo *philo, t_info_philo *info_philo)
{
	pthread_mutex_lock(&info_philo->key_print);
	if (check_philo(philo, info_philo) || info_philo->flag == -1)
	{
		pthread_mutex_unlock(&info_philo->key_print);
		start_dying(philo, info_philo);
		return (1);
	}
	printf("%llu %d is sleeping\n", get_current_time(), philo->num);
	pthread_mutex_unlock(&info_philo->key_print);
	if (philo_usleep(info_philo->time_to_sleep * 1000, philo) == 1)
		return (1);
	return (0);
}