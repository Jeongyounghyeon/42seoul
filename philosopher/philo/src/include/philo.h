/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:35:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/27 19:35:21 by youjeong         ###   ########.fr       */
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

typedef pthread_mutex_t t_fork;

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
	t_fork		*lfork;
	t_fork		*rfork;
}t_philo;

void	input_handler(t_info_philo *info_philo, char **argv);
void	set_table(t_philo **philos, t_fork **forks, t_info_philo *info_philo);

/* init */
void	init_table(t_philo *philos, t_fork *forks, t_info_philo *info_philo);
void	init_philo(t_philo *philo, int num, t_fork *lfork, t_fork *rfork);
t_philo	*get_philos(int n);
t_fork	*get_forks(int n);

// exception
void	parameter_exception(void);

// utils
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

#endif