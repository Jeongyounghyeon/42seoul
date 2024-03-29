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
	int				(*eating_routine)(t_philo *, t_info_philo *);

	philo = (t_philo *)arg_philo;
	info_philo = philo->info_philo;
	if (info_philo->nbr_of_philos == 1)
		eating_routine = eating_routine_1;
	else if (philo->num <= info_philo->nbr_of_philos / 2)
		eating_routine = wait_eating_odd;
	else
		eating_routine = wait_eating_even;
	while ((eating_routine(philo, info_philo) != 1)
		&& (start_sleeping(philo, info_philo) != 1)
		&& (start_thinking(philo, info_philo) != 1))
		continue ;
	exit(0);
}

static int	wait_eating_odd(t_philo *philo, t_info_philo *info_philo)
{
	sem_wait(philo->forks);
	if (print_philo_state(FORMAT_TAKE, philo, info_philo))
		return (1);
	sem_wait(philo->forks);
	if (print_philo_state(FORMAT_TAKE, philo, info_philo)
		|| print_philo_state(FORMAT_EAT, philo, info_philo))
		return (1);
	philo->last_eat_time = get_current_time();
	if (philo_usleep(1000 * info_philo->time_to_eat, philo))
		return (1);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (info_philo->time_to_must_eat != -1)
		check_more_eat(philo, philo->info_philo);
	return (0);
}

static int	wait_eating_even(t_philo *philo, t_info_philo *info_philo)
{
	sem_wait(info_philo->key_fork);
	sem_wait(philo->forks);
	if (print_philo_state(FORMAT_TAKE, philo, info_philo))
		return (1);
	sem_wait(philo->forks);
	sem_post(info_philo->key_fork);
	if (print_philo_state(FORMAT_TAKE, philo, info_philo)
		|| print_philo_state(FORMAT_EAT, philo, info_philo))
		return (1);
	philo->last_eat_time = get_current_time();
	if (philo_usleep(1000 * info_philo->time_to_eat, philo))
		return (1);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (info_philo->time_to_must_eat != -1)
		check_more_eat(philo, philo->info_philo);
	return (0);
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
