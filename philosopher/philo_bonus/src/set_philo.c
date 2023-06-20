/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:35:42 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/20 17:52:45 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_routine_philo(t_philo *philos, t_info_philo *info_philo);
int		set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo);
void	execute_philo(t_philo *philos, t_info_philo *info_philo);

int	set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo)
{
	*philos = get_philos(info_philo->nbr_of_philos);
	if (!*philos)
		return (ERROR);
	*forks = get_forks(info_philo->nbr_of_philos);
	if (!*forks)
	{
		free(*philos);
		return (ERROR);
	}
	pthread_mutex_init(&info_philo->key_print, 0);
	pthread_mutex_init(&info_philo->more_eat_mutex, 0);
	pthread_mutex_init(&info_philo->flag_mutex, 0);
	init_table(*philos, *forks, info_philo);
	info_philo->more_eat = 0;
	info_philo->flag = 0;
	return (0);
}

void	set_routine_philo(t_philo *philos, t_info_philo *info_philo)
{
	int	i;

	i = 0;
	while (i < info_philo->nbr_of_philos)
	{
		pthread_create(&philos[i].thread, 0,
			(void *)routine, (void *)&philos[i]);
		i++;
	}
}

void	execute_philo(t_philo *philos, t_info_philo *info_philo)
{
	int	i;

	pthread_mutex_lock(&info_philo->flag_mutex);
	get_current_time();
	info_philo->flag = 1;
	pthread_mutex_unlock(&info_philo->flag_mutex);
	i = 0;
	while (i < info_philo->nbr_of_philos)
	{
		pthread_join(philos[i].thread, 0);
		i++;
	}
}
