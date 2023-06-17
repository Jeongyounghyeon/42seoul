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
	if (philo->num % 2 != 0 || philo->num == philo->info_philo->nbr_of_philos)
		eating_routin = wait_eating_odd;
	else
		eating_routin = wait_eating_even;
	wait_setting(philo);
	philo->last_eat_time = get_current_time();
	if (philo->num % 2 == 0)
	{
		if (philo_usleep(1000 * philo->info_philo->time_to_eat, philo) == 1)
			return (0);
	}
	else if (philo->num == philo->info_philo->nbr_of_philos
		&& philo_usleep(2 * 1000 * philo->info_philo->time_to_eat, philo) == 1)
		return (0);
	while ((eating_routin(philo, philo->info_philo) != 1)
		&& (start_sleeping(philo, philo->info_philo) != 1)
		&& (start_thinking(philo, philo->info_philo)) != 1)
		continue ;
	return (0);
}

static int	wait_eating_odd(t_philo *philo, t_info_philo *info_philo)
{
	pthread_mutex_lock(philo->lfork);
	if (print_philo_state_in_mutex(philo, taking1, info_philo))
	{
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	pthread_mutex_lock(philo->rfork);
	if (print_philo_state_in_mutex(philo, taking2, info_philo) ||
		philo_usleep(1000 * info_philo->time_to_eat, philo) == 1)
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		return (1);
	}
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (0);
}

static int	wait_eating_even(t_philo *philo, t_info_philo *info_philo)
{
	pthread_mutex_lock(philo->rfork);
	if (print_philo_state_in_mutex(philo, taking1, info_philo))
	{
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	pthread_mutex_lock(philo->lfork);
	if (print_philo_state_in_mutex(philo, taking2, info_philo) ||
		philo_usleep(1000 * info_philo->time_to_eat, philo) == 1)
	{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
		return (1);
	}
	pthread_mutex_unlock(philo->rfork);
	pthread_mutex_unlock(philo->lfork);
	return (0);
}

static int	start_thinking(t_philo *philo, t_info_philo *info_philo)
{
	if (print_philo_state_in_mutex(philo, thinking, info_philo))
		return (1);
	if (info_philo->nbr_of_philos % 2 != 0
		&& philo_usleep(1000 * \
			(2 * info_philo->time_to_eat - info_philo->time_to_sleep), \
			philo) == 1)
		return (0);
	return (0);
}

static int	start_sleeping(t_philo *philo, t_info_philo *info_philo)
{
	if (print_philo_state_in_mutex(philo, sleeping, info_philo))
		return (1);
	if (philo_usleep(info_philo->time_to_sleep * 1000, philo) == 1)
		return (1);
	return (0);
}
