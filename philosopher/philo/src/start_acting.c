/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:14:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/27 15:16:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		start_thinking(t_info_philo infoPhilo, t_philo *philo);
void	start_sleeping(void);
void	start_eating(void);

int	start_thinking(t_info_philo info_philo, t_philo *philo)
{
	struct timeval	tv;

	if (gettimeofday(&tv, 0) == ERROR)
		return (ERROR);

	// fork 대기
	return (0);
}

void	start_sleeping(void)
{
	struct timeval	tv;
	char			*str;


	return ;
}

void	start_eating(void)
{
	return ;
}
