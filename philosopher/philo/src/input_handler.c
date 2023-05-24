/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:32:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/23 22:47:57 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_handler(t_info_philo *info_philo, char **argv);

void	input_handler(t_info_philo *info_philo, char **argv)
{
	info_philo->number_of_philosophers = ft_atoi(argv[1]);
	info_philo->time_to_die = ft_atoi(argv[2]);
	info_philo->time_to_eat = ft_atoi(argv[3]);
	info_philo->time_to_sleep = ft_atoi(argv[4]);
	info_philo->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return ;
}
