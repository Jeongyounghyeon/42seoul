/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:51:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/13 13:16:11 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		check_philo(t_philo *philo, t_info_philo *info_philo);
int		philo_usleep(useconds_t usec, t_philo *philo);
void	wait_setting(t_info_philo *info_philo);

int	check_philo(t_philo *philo, t_info_philo *info_philo)
{
	if (get_current_time() - (philo->last_eat_time)
		>= (info_philo->time_to_die))
		return (1);
	return (0);
}

int	philo_usleep(useconds_t usec, t_philo *philo)
{
	t_ms	usec_end;

	usec_end = get_current_time() + (t_ms)(usec / 1000);
	while (get_current_time() < usec_end)
	{
		if (usleep(1000) == ERROR)
			return (ERROR);
		if (check_philo(philo, philo->info_philo))
		{
			print_philo_state_in_mutex(philo, dying, philo->info_philo);
			return (1);
		}
	}
	return (0);
}

void	wait_setting(t_info_philo *info_philo)
{	
	while (1)
	{
		if (get_mutex_value(&info_philo->flag_mutex, &info_philo->flag) == 1)
			break ;
	}
}
