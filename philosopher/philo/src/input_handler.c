/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:32:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/12 18:32:35 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_handler(t_info_philo *info_philo, char **argv);
void	set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo);

void	input_handler(t_info_philo *info_philo, char **argv)
{
	info_philo->nbr_of_philos = ft_atoi(argv[1]);
	info_philo->time_to_die = (t_ms)ft_atoi(argv[2]);
	info_philo->time_to_eat = (t_ms)ft_atoi(argv[3]);
	info_philo->time_to_sleep = (t_ms)ft_atoi(argv[4]);
	info_philo->time_to_must_eat = (t_ms)ft_atoi(argv[5]);
	return ;
}

void	set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo)
{
	*philos = get_philos(info_philo->nbr_of_philos);
	*forks = get_forks(info_philo->nbr_of_philos);
	info_philo->key_print = (pthread_mutex_t *)malloc(1 * sizeof(pthread_mutex_t));
	pthread_mutex_init(info_philo->key_print, 0);
	if (!info_philo->key_print)
		printf("Not enough memory!\n");
	if (!(*philos) || !(*forks) || !info_philo->key_print)
		exit(1);
	init_table(*philos, *forks, info_philo);
	info_philo->flag = 0;
}