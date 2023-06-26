/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:38:19 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/18 18:43:35 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>

typedef uint64_t	t_ms;
typedef sem_t		t_fork;

typedef struct s_info_philo
{
	int		nbr_of_philos;
	t_ms	time_to_die;
	t_ms	time_to_eat;
	t_ms	time_to_sleep;
	t_ms	time_to_think;
	int		time_to_must_eat;
	sem_t	*key_print;
	sem_t	*key_fork;
	sem_t	*more_eat;
}t_info_philo;

typedef struct s_philo
{
	int				num;
	pid_t			pid;
	t_fork			*forks;
	t_ms			last_eat_time;
	int				time_to_eat;
	t_info_philo	*info_philo;
}t_philo;

#endif