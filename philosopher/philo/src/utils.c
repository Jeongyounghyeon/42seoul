/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:50:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/12 21:05:08 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ms	get_current_time(void);

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
