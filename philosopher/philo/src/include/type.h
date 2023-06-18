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

typedef uint64_t		t_ms;
typedef pthread_mutex_t	t_fork;

typedef struct s_info_philo
{
	int				nbr_of_philos;
	t_ms			time_to_die;
	t_ms			time_to_eat;
	t_ms			time_to_sleep;
	int				time_to_must_eat;
	pthread_mutex_t	key_print;
	int				more_eat;
	pthread_mutex_t	more_eat_mutex;
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
	int				time_to_eat;
	t_info_philo	*info_philo;
}t_philo;

#endif