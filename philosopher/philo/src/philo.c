/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:35:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/27 19:40:28 by youjeong         ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	if (argc < 5 || argc > 6)
		parameter_exception();
	input_handler(&info_philo, argv);
	set_table(&philos, &forks, &info_philo);
	test(philos, forks, &info_philo);
}

void	test(t_philo *philos, t_fork *forks, t_info_philo *info_philo)
{
	printf("%-45s : %d\n", "number_of_philosophers", info_philo->number_of_philosophers);
	printf("%-45s : %d\n", "number_of_times_each_philosopher_must_eat", info_philo->number_of_times_each_philosopher_must_eat);
	printf("%-45s : %d\n", "time_to_die", info_philo->time_to_die);
	printf("%-45s : %d\n", "time_to_eat", info_philo->time_to_eat);
	printf("%-45s : %d\n", "time_to_sleep", info_philo->time_to_sleep);
	printf("------------------------------------------------------------------------------------------------------------\n");
	for(int i = 0; i < info_philo->number_of_philosophers; i++)
	{
		printf("philos[%d]\n", i);
		printf("number : %d\n", philos[i].num);
		printf("lfork : %p\n", philos[i].lfork);
		printf("rfork : %p\n", philos[i].rfork);
	}
	printf("------------------------------------------------------------------------------------------------------------\n");
	for(int i = 0; i < info_philo->number_of_philosophers; i++)
	{
		printf("forks[%d]\n", i);
		printf("address : %p\n", &forks[i]);
	}
	printf("------------------------------------------------------------------------------------------------------------\n");
}