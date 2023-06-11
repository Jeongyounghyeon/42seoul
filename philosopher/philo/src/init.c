/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:05:13 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/11 18:06:53 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	init_table(t_philo *philos, t_fork *forks, t_info_philo *info_philo);
void	init_philo(t_philo *philo, int num, t_fork *lfork, t_fork *rfork);
t_philo	*get_philos(int n);
t_fork	*get_forks(int n);

void	init_table(t_philo *philos, t_fork *forks, t_info_philo *info_philo)
{
	int	i;

	i = 0;
	while (i < info_philo->nbr_of_philos - 1)
	{
		init_philo(&philos[i], philos[i].num, &forks[i], &forks[i + 1]);
		philos[i].info_philo = info_philo;
		i++;
	}
	init_philo(&philos[i], philos[i].num, &forks[i], &forks[0]);
}

void	init_philo(t_philo *philo, int num, t_fork *lfork, t_fork *rfork)
{
	philo->num = num;
	philo->lfork = lfork;
	philo->rfork = rfork;
}

t_philo	*get_philos(int n)
{
	t_philo	*philos;
	int		i;

	i = 0;
	if (n == 0)
		return 0;
	philos = (t_philo *)malloc(n * sizeof(t_philo));
	if (philos == 0)
	{
		printf("Not enough memory!\n");
		return (0);
	}
	while (i < n)
	{
		init_philo(&philos[i], i + 1, 0, 0);
		i++;
	}
	return (philos);
}

t_fork	*get_forks(int n)
{
	t_fork	*forks;
	int		i;

	i = 0;
	if (n == 0)
		return 0;
	forks = (t_fork *)malloc(n * sizeof(t_fork));
	if (forks == 0)
	{
		printf("Not enough memory!\n");
		return (0);
	}
	while (i < n)
		pthread_mutex_init(&forks[i++], 0);
	return (forks);
}
