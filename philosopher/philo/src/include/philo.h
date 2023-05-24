/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:35:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/23 22:47:52 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_info_philo
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}t_info_philo;

typedef struct s_philo
{
	pthread_t	thread;
	int			num;
}t_philo;

void	input_handler(t_info_philo *info_philo, char **argv);

// exception
void	parameter_exception(void);

// utils
int		ft_atoi(const char *str);

#endif