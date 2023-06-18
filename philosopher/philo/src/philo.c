/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:35:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/08 16:51:25 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			main(int argc, char **argv);
static void	execute_philo(t_philo *philos, t_info_philo *info_philo);

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_info_philo	info_philo;
	t_fork			*forks;

	if (argc < 5 || argc > 6)
	{
		parameter_exception();
		return (0);
	}
	input_handler(&info_philo, argv, argc);
	if (check_input(&info_philo))
		return (1);
	if (set_table(&philos, &forks, &info_philo) == ERROR)
		return (1);
	set_routine_philo(philos, &info_philo);
	execute_philo(philos, &info_philo);
	destroy_mutexes(forks, info_philo.nbr_of_philos);
	free(philos);
	free(forks);
	return (0);
}

static void	execute_philo(t_philo *philos, t_info_philo *info_philo)
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
