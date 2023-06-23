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
void	*monitoring_more_eat(void *args);

int	set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo)
{
	*philos = get_philos(info_philo->nbr_of_philos);
	if (!*philos)
		return (ERROR);
	sem_unlink("forks");
	*forks = sem_open("forks", O_CREAT, 0777, info_philo->nbr_of_philos);
	if (*forks == SEM_FAILED)
		return (ERROR);
	sem_unlink("forks");
	pthread_mutex_init(&info_philo->flag_mutex, 0);
	init_table(*philos, *forks, info_philo);
	sem_unlink("key_print");
	info_philo->key_print = sem_open("key_print", O_CREAT, 0777, 1);
	if (info_philo->key_print == SEM_FAILED)
		return (ERROR);
	sem_unlink("key_print");
	sem_unlink("more_eat");
	info_philo->key_print = sem_open("more_eat", O_CREAT, 0777, info_philo->nbr_of_philos);
	if (info_philo->key_print == SEM_FAILED)
		return (ERROR);
	sem_unlink("more_eat");
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
	pthread_t	monitoring;
	int			i;

	pthread_mutex_lock(&info_philo->flag_mutex);
	get_current_time();
	info_philo->flag = 1;
	pthread_mutex_unlock(&info_philo->flag_mutex);
	// 예외 처리 필요
	pthread_create(&monitoring, 0,
		(void *)monitoring_more_eat, (void *)info_philo);
	pthread_detach(monitoring);
	i = 0;
	while (i < info_philo->nbr_of_philos)
	{
		pthread_join(philos[i].thread, 0);
		i++;
	}
}

void	*monitoring_more_eat(void *args)
{
	t_info_philo	*info_philo;
	int				i;

	info_philo = (t_info_philo *)args;
	i = 0;
	while (i++ < info_philo->nbr_of_philos)
		sem_wait(info_philo->more_eat);
	printf("test\n");
	return (0);
}
