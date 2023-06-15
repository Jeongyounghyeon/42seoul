/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:32:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/12 21:04:57 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_handler(t_info_philo *info_philo, char **argv);
int		set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo);

void	input_handler(t_info_philo *info_philo, char **argv)
{
	info_philo->nbr_of_philos = ft_atoi(argv[1]);
	info_philo->time_to_die = (t_ms)ft_atoi(argv[2]);
	info_philo->time_to_eat = (t_ms)ft_atoi(argv[3]);
	info_philo->time_to_sleep = (t_ms)ft_atoi(argv[4]);
	info_philo->time_to_must_eat = (t_ms)ft_atoi(argv[5]);
	return ;
}

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
	pthread_mutex_init(&info_philo->flag_mutex, 0);
	init_table(*philos, *forks, info_philo);
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
