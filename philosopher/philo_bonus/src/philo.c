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

int	main(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_info_philo	info_philo;
	t_fork			*forks;

	forks = 0;
	if ((input_handler(&info_philo, argv, argc) == TRUE)
		&& (set_table(&philos, &forks, &info_philo) == 0))
	{
		execute_philo(philos, &info_philo);
		free(philos);
	}
	sem_close(info_philo.key_print);
	sem_close(forks);
	sem_close(info_philo.more_eat);
	sem_close(info_philo.key_fork);
	return (0);
}
