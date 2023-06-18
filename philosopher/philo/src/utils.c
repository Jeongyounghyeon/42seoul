/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:50:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/13 09:36:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_current_time(void);
void	destroy_mutexes(pthread_mutex_t *mutexes, t_info_philo *info_philo);
void	set_mutex_value(pthread_mutex_t *mutex, int *ptr_value, int value);
int		get_mutex_value(pthread_mutex_t *mutex, int *ptr_value);

t_ms	get_current_time(void)
{
	static t_ms		time_start;
	t_ms			time_ms;
	struct timeval	tv;

	gettimeofday(&tv, 0);
	if (time_start == 0)
	{
		time_start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		return (time_start);
	}
	time_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - time_start;
	return (time_ms);
}

void	destroy_mutexes(pthread_mutex_t *mutexes, t_info_philo *info_philo)
{
	int	i;

	i = 0;
	while (i < info_philo->nbr_of_philos)
		pthread_mutex_destroy(&mutexes[i++]);
	pthread_mutex_destroy(&info_philo->flag_mutex);
	pthread_mutex_destroy(&info_philo->key_print);
	pthread_mutex_destroy(&info_philo->more_eat_mutex);
}

void	set_mutex_value(pthread_mutex_t *mutex, int *ptr_value, int value)
{
	pthread_mutex_lock(mutex);
	*ptr_value = value;
	pthread_mutex_unlock(mutex);
}

int	get_mutex_value(pthread_mutex_t *mutex, int *ptr_value)
{
	int	value;

	pthread_mutex_lock(mutex);
	value = *ptr_value;
	pthread_mutex_unlock(mutex);
	return (value);
}
