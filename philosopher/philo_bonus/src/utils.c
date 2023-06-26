/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:50:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/13 09:36:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_current_time(void);
int		print_philo_state( \
			char *format, t_philo *philo, t_info_philo *info_philo);

t_ms	get_current_time(void)
{
	static t_ms		time_start;
	t_ms			time_ms;
	struct timeval	tv;

	gettimeofday(&tv, 0);
	if (time_start == 0)
	{
		time_start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
		return (time_start);
	}
	time_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - time_start;
	return (time_ms);
}

int	print_philo_state( \
		char *format, t_philo *philo, t_info_philo *info_philo)
{
	int				rtn;

	rtn = 0;
	sem_wait(info_philo->key_print);
	if (check_philo(philo, info_philo))
	{
		printf(FORMAT_DIE, get_current_time(), philo->num);
		return (1);
	}
	else
		printf(format, get_current_time(), philo->num);
	sem_post(info_philo->key_print);
	return (rtn);
}
