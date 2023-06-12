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

int		main(int argc, char **argv);
void	set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo);
void	test(t_philo *philos, t_fork *forks, t_info_philo *s_info_philo);

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_info_philo	info_philo;
	t_fork			*forks;

	if (argc < 5 || argc > 6)
		parameter_exception();
	input_handler(&info_philo, argv);
	set_table(&philos, &forks, &info_philo);
	// test(philos, forks, &info_philo);
	
	for (int i = 0; i < info_philo.nbr_of_philos; i++) {
		if (pthread_create(&philos[i].thread, 0, (void *)routine, (void *)&philos[i]) != 0)
			printf("thread create error\n");
	}
	get_current_time();
	pthread_mutex_lock(&info_philo.flag_mutex);
	info_philo.flag = 1;
	pthread_mutex_unlock(&info_philo.flag_mutex);
	for (int i = 0; i < info_philo.nbr_of_philos; i++)
		pthread_join(philos[i].thread, 0);
	return (0);
}

void	test(t_philo *philos, t_fork *forks, t_info_philo *info_philo)
{
	printf("%-45s : %d\n", "nbr_of_philos", info_philo->nbr_of_philos);
	printf("%-45s : %llu\n", "time_to_must_eat", info_philo->time_to_must_eat);
	printf("%-45s : %llu\n", "time_to_die", info_philo->time_to_die);
	printf("%-45s : %llu\n", "time_to_eat", info_philo->time_to_eat);
	printf("%-45s : %llu\n", "time_to_sleep", info_philo->time_to_sleep);
	printf("%-45s : %p\n", "key_print", info_philo->key_print);
	printf("------------------------------------------------------------------------------------------------------------\n");
	for(int i = 0; i < info_philo->nbr_of_philos; i++)
	{
		printf("philos[%d]\n", i);
		printf("number : %d\n", philos[i].num);
		printf("lfork : %p\n", philos[i].lfork);
		printf("rfork : %p\n", philos[i].rfork);
		printf("address : %p\n", &philos[i].thread);
	}
	printf("------------------------------------------------------------------------------------------------------------\n");
	for(int i = 0; i < info_philo->nbr_of_philos; i++)
	{
		printf("forks[%d]\n", i);
		printf("address : %p\n", &forks[i]);
	}
	printf("------------------------------------------------------------------------------------------------------------\n");
}