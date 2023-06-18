/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:10:19 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/18 19:10:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		print_philo_state( \
			char *format, t_philo *philo, t_info_philo *info_philo);
void	parameter_exception(void);

void	parameter_exception(void)
{
	printf(\
"The philo program requires a factor of 5~6 int numbers.\n \
1. number_of_philosophers\n \
2. time_to_die\n \
3. time_to_eat\n \
4. time_to_sleep\n \
5. number_of_times_each_philosopher_must_eat(Option)\n");
}

int	print_philo_state( \
		char *format, t_philo *philo, t_info_philo *info_philo)
{
	int				rtn;

	rtn = 0;
	pthread_mutex_lock(&info_philo->key_print);
	if (get_mutex_value(&info_philo->flag_mutex, &info_philo->flag) == -1)
		rtn = 1;
	else if (check_philo(philo, info_philo))
	{
		set_mutex_value(&info_philo->flag_mutex, &info_philo->flag, -1);
		printf(FORMAT_DIE, get_current_time(), philo->num);
		rtn = 1;
	}
	else
		printf(format, get_current_time(), philo->num);
	pthread_mutex_unlock(&info_philo->key_print);
	return (rtn);
}
