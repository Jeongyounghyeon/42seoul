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

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef uint64_t		t_ms;
typedef pthread_mutex_t	t_fork;

typedef struct s_info_philo
{
	int				nbr_of_philos;
	t_ms			time_to_die;
	t_ms			time_to_eat;
	t_ms			time_to_sleep;
	t_ms			time_to_must_eat;
	pthread_mutex_t	key_print;
	int				flag;
	pthread_mutex_t	flag_mutex;
}t_info_philo;

typedef struct s_philo
{
	pthread_t		thread;
	int				num;
	t_fork			*lfork;
	t_fork			*rfork;
	t_ms			last_eat_time;
	t_info_philo	*info_philo;
}t_philo;

typedef enum e_state {thinking, eating, sleeping, dying, taking}t_state;

void	input_handler(t_info_philo *info_philo, char **argv);
int		set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo);
void	set_routine_philo(t_philo *philos, t_info_philo *info_philo);

/* init */
void	init_table(t_philo *philos, t_fork *forks, t_info_philo *info_philo);
void	init_philo(t_philo *philo, int num, t_fork *lfork, t_fork *rfork);
t_philo	*get_philos(int n);
t_fork	*get_forks(int n);

/* routine */
void	*routine(void *arg_philo);
int		check_philo(t_philo *philo, t_info_philo *info_philo);
int		start_dying(t_philo *philo, t_info_philo *info_philo);
int		philo_usleep(useconds_t usec, t_philo *philo);

/* exception */
void	parameter_exception(void);

/* utils */
int		ft_atoi(const char *str);
t_ms	get_current_time(void);
#endif