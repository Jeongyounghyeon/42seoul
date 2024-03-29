/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:35:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/11 18:06:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

# include "type.h"
# include "state.h"
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

/* input_handle */
int		input_handler(t_info_philo *info_philo, char **argv, int argc);

/* set_philo */
int		set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo);
int		set_routine_philo(t_philo *philos, t_info_philo *info_philo);
void	execute_philo(t_philo *philos, t_info_philo *info_philo);
void	set_eating_routine(t_philo *philo, t_info_philo *info_philo, \
							int (**eating_routine)(t_philo *, t_info_philo *));

/* init */
void	init_table(t_philo *philos, t_fork *forks, t_info_philo *info_philo);
void	init_philo(t_philo *philo, int num, t_fork *lfork, t_fork *rfork);
t_philo	*get_philos(int n);
t_fork	*get_forks(int n);

/* routine */
void	*routine(void *arg_philo);
int		wait_eating_odd(t_philo *philo, t_info_philo *info_philo);
int		wait_eating_even(t_philo *philo, t_info_philo *info_philo);
int		eating_routine_1(t_philo *philo, t_info_philo *info_philo);

/* monotoring */
int		check_philo(t_philo *philo, t_info_philo *info_philo);
void	check_more_eat(t_philo *philo, t_info_philo *info_philo);
int		philo_usleep(useconds_t usec, t_philo *philo);
int		wait_setting(t_info_philo *info_philo);

/* utils */
int		ft_atoi(const char *str);
t_ms	get_current_time(void);
void	destroy_mutexes(pthread_mutex_t *mutexes, t_info_philo *info_philo);
void	set_mutex_value(pthread_mutex_t *mutex, int *ptr_value, int value);
int		get_mutex_value(pthread_mutex_t *mutex, int *ptr_value);
int		print_philo_state(\
			char *format, t_philo *philo, t_info_philo *info_philo);

#endif
