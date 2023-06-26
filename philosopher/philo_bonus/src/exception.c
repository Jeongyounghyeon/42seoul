/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:33:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/26 19:43:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating_routine_1(t_philo *philo, t_info_philo *info_philo);

int	eating_routine_1(t_philo *philo, t_info_philo *info_philo)
{
	sem_wait(philo->forks);
	if (print_philo_state(FORMAT_TAKE, philo, info_philo))
		return (1);
	philo_usleep(1000 * info_philo->time_to_die, philo);
	return (1);
}
