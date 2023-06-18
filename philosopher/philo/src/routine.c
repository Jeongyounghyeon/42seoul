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
	t_philo			*philo;
	t_info_philo	*info_philo;
	int				(*eating_routin)(t_philo *, t_info_philo *);

	philo = (t_philo *)arg_philo;
	info_philo = philo->info_philo;
	if (philo->num % 2 != 0 || philo->num == info_philo->nbr_of_philos)
		eating_routin = wait_eating_odd;
	else
		eating_routin = wait_eating_even;
	wait_setting(info_philo);
	philo->last_eat_time = get_current_time();
	if (philo->num % 2 == 0)
	{
		if (philo_usleep(1000 * info_philo->time_to_eat, philo) == 1)
			return (0);
	}
	else if (philo->num == info_philo->nbr_of_philos
		&& philo_usleep(2 * 1000 * info_philo->time_to_eat, philo) == 1)
		return (0);
	while ((eating_routin(philo, info_philo) != 1)
		&& (start_sleeping(philo, info_philo) != 1)
		&& (start_thinking(philo, info_philo) != 1))
		continue ;
	return (0);
}

static int	wait_eating_odd(t_philo *philo, t_info_philo *info_philo)
{
	int	rtn;

	rtn = 0;
	pthread_mutex_lock(philo->lfork);
	if (print_philo_state(FORMAT_TAKE, philo, info_philo))
	{
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	pthread_mutex_lock(philo->rfork);
	print_philo_state(FORMAT_TAKE, philo, info_philo);
	print_philo_state(FORMAT_EAT, philo, info_philo);
	philo->last_eat_time = get_current_time();
	if (philo_usleep(1000 * info_philo->time_to_eat, philo))
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	if (info_philo->time_to_must_eat != -1)
		check_more_eat(philo, philo->info_philo);
	return (rtn);
}

static int	wait_eating_even(t_philo *philo, t_info_philo *info_philo)
{
	int	rtn;

	rtn = 0;
	pthread_mutex_lock(philo->rfork);
	if (print_philo_state(FORMAT_TAKE, philo, info_philo))
	{
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	pthread_mutex_lock(philo->lfork);
	print_philo_state(FORMAT_TAKE, philo, info_philo);
	print_philo_state(FORMAT_EAT, philo, info_philo);
	philo->last_eat_time = get_current_time();
	if (philo_usleep(1000 * info_philo->time_to_eat, philo))
	{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	if (info_philo->time_to_must_eat != -1)
		check_more_eat(philo, philo->info_philo);
	return (rtn);
}

static int	start_thinking(t_philo *philo, t_info_philo *info_philo)
{
	if (print_philo_state(FORMAT_THINK, philo, info_philo))
		return (1);
	if (philo_usleep(1000 * info_philo->time_to_think, philo) == 1)
		return (1);
	return (0);
}

static int	start_sleeping(t_philo *philo, t_info_philo *info_philo)
{
	if (print_philo_state(FORMAT_SLEEP, philo, info_philo))
		return (1);
	if (philo_usleep(info_philo->time_to_sleep * 1000, philo) == 1)
		return (1);
	return (0);
}
