/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:51:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/13 13:16:11 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		check_philo(t_philo *philo, t_info_philo *info_philo);
void	check_more_eat(t_philo *philo, t_info_philo *info_philo);
int		philo_usleep(useconds_t usec, t_philo *philo);
int		wait_setting(t_info_philo *info_philo);

int	check_philo(t_philo *philo, t_info_philo *info_philo)
{
	if (get_current_time() - (philo->last_eat_time)
		>= (info_philo->time_to_die))
		return (1);
	return (0);
}

void	check_more_eat(t_philo *philo, t_info_philo *info_philo)
{
	if (++(philo->time_to_eat) == info_philo->time_to_must_eat)
	{
		pthread_mutex_lock(&info_philo->more_eat_mutex);
		if (++(info_philo->more_eat) >= info_philo->nbr_of_philos)
		{
			pthread_mutex_lock(&info_philo->key_print);
			if (get_mutex_value(&info_philo->flag_mutex, &info_philo->flag)
				!= -1)
			{
				set_mutex_value(&info_philo->flag_mutex, &info_philo->flag, -1);
				printf(\
					"%llu All philosophers ate at least times as they should.\n",
					get_current_time());
			}
			pthread_mutex_unlock(&info_philo->key_print);
		}
		pthread_mutex_unlock(&info_philo->more_eat_mutex);
	}
}

int	philo_usleep(useconds_t usec, t_philo *philo)
{
	t_ms	usec_end;

	usec_end = get_current_time() + (t_ms)(usec / 1000);
	while (get_current_time() < usec_end)
	{
		if (usleep(1000) == ERROR)
			return (ERROR);
		else if (check_philo(philo, philo->info_philo))
		{
			print_philo_state(FORMAT_DIE, philo, philo->info_philo);
			return (1);
		}
	}
	return (0);
}

int	wait_setting(t_info_philo *info_philo)
{	
	while (1)
	{
		if (get_mutex_value(&info_philo->flag_mutex, &info_philo->flag) == 1)
			return (0);
		else if (get_mutex_value(&info_philo->flag_mutex, &info_philo->flag) \
			== -1)
			return (ERROR);
	}
}
