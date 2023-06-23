/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:05:13 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/12 20:59:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(t_philo *philos, t_fork *forks, t_info_philo *info_philo);
void	init_philo(t_philo *philo, int num, t_fork *forks);
t_philo	*get_philos(int n);

void	init_table(t_philo *philos, t_fork *forks, t_info_philo *info_philo)
{
	int	i;

	i = 0;
	while (i < info_philo->nbr_of_philos)
	{
		init_philo(&philos[i], philos[i].num, forks);
		philos[i].info_philo = info_philo;
		i++;
	}
}

void	init_philo(t_philo *philo, int num, t_fork *forks)
{
	philo->num = num;
	philo->forks = forks;
	philo->time_to_eat = 0;
}

t_philo	*get_philos(int n)
{
	t_philo	*philos;
	int		i;

	i = 0;
	if (n == 0)
		return (0);
	philos = (t_philo *)malloc(n * sizeof(t_philo));
	if (!philos)
	{
		printf("Not enough memory!\n");
		return (0);
	}
	while (i < n)
	{
		init_philo(&philos[i], i + 1, 0);
		i++;
	}
	return (philos);
}
