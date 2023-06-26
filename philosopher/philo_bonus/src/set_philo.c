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
int		set_philos(t_philo *philos, t_info_philo *info_philo);
void	*monitoring_more_eat(void *args);

int	set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo)
{
	*philos = get_philos(info_philo->nbr_of_philos);
	if (!*philos)
		return (ERROR);
	if (make_sem(forks, "forks", info_philo->nbr_of_philos) == ERROR
		|| make_sem(&info_philo->key_print, "key_print", 1) == ERROR
		|| make_sem(&info_philo->more_eat, "more_eat", 0) == ERROR
		|| make_sem(&info_philo->key_fork, "key_fork", 1) == ERROR)
	{
		free(philos);
		return (ERROR);
	}
	init_table(*philos, *forks, info_philo);
	return (0);
}

void	execute_philo(t_philo *philos, t_info_philo *info_philo)
{
	pid_t	pid;
	int		i;

	get_current_time();
	pid = fork();
	if (pid == 0)
		monitoring_more_eat((void *)info_philo);
	i = set_philos(philos, info_philo);
	if (i != ERROR)
	{
		waitpid(-1, 0, 0);
		i = 0;
		while (i < info_philo->nbr_of_philos)
			kill(philos[i++].pid, SIGKILL);
	}
	kill(pid, SIGKILL);
}

int	set_philos(t_philo *philos, t_info_philo *info_philo)
{
	int	i;

	i = 0;
	while (i < info_philo->nbr_of_philos)
	{
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			routine((void *)&philos[i]);
		else if (philos[i].pid == -1)
		{
			printf("fork error\n");
			break ;
		}
		i++;
	}
	if (i != info_philo->nbr_of_philos)
	{
		while (i-- > 0)
			kill(philos[i++].pid, SIGKILL);
		return (ERROR);
	}
	return (0);
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
