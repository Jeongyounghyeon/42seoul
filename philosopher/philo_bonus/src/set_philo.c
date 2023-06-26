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
	init_table(*philos, *forks, info_philo);
	sem_unlink("key_print");
	info_philo->key_print = sem_open("key_print", O_CREAT, 0777, 1);
	if (info_philo->key_print == SEM_FAILED)
		return (ERROR);
	sem_unlink("key_print");
	sem_unlink("more_eat");
	info_philo->more_eat = sem_open("more_eat", O_CREAT, 0777, 0);
	if (info_philo->more_eat == SEM_FAILED)
		return (ERROR);
	sem_unlink("more_eat");
	sem_unlink("key_fork");
	info_philo->key_fork = sem_open("key_fork", O_CREAT, 0777, 1);
	if (info_philo->key_fork == SEM_FAILED)
		return (ERROR);
	sem_unlink("key_fork");
	return (0);
}

void	execute_philo(t_philo *philos, t_info_philo *info_philo)
{
	pid_t	pid;
	int		i;

	i = 0;
	get_current_time();
	pid = fork();
	if (pid == 0)
		monitoring_more_eat((void *)info_philo);
	while (i < info_philo->nbr_of_philos)
	{
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			routine((void *)&philos[i]);
		else if (philos[i].pid == -1)
			printf("fork error\n");
		i++;
	}
	waitpid(-1, 0, 0);
	i = 0;
	while (i < info_philo->nbr_of_philos)
		kill(philos[i++].pid, SIGKILL);
	kill(pid, SIGKILL);
}

void	*monitoring_more_eat(void *args)
{
	t_info_philo	*info_philo;
	int				i;

	info_philo = (t_info_philo *)args;
	i = 0;
	while (i++ < info_philo->nbr_of_philos)
		sem_wait(info_philo->more_eat);
	sem_wait(info_philo->key_print);
	printf(\
		"%llu All philosophers ate at least times as they should.\n",
		get_current_time());
	exit(1);
}
