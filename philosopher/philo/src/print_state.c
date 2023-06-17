/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:04:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/17 15:59:25 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			print_philo_state_in_mutex(\
	t_philo *philo, t_state state, t_info_philo *info_philo);
static int	check_before_print_philo(t_philo *philo, t_info_philo *info_philo);
static void	print_philo_state(t_philo *philo, t_state state);
static void	check_more_eat(t_philo *philo, t_info_philo *info_philo);
static void	print_must_eat_message(void);

int	print_philo_state_in_mutex(\
	t_philo *philo, t_state state, t_info_philo *info_philo)
{
	int				rtn_befor_print;
	pthread_mutex_t	*key_print;
	int				rtn;

	info_philo = philo->info_philo;
	key_print = &info_philo->key_print;
	rtn = 0;
	pthread_mutex_lock(key_print);
	rtn_befor_print = check_before_print_philo(philo, info_philo);
	if (rtn_befor_print == 0)
		print_philo_state(philo, state);
	else
	{
		if (rtn_befor_print == 1)
		{
			state = dying;
			print_philo_state(philo, state);
		}
		rtn = 1;
	}
	pthread_mutex_unlock(key_print);
	return (rtn);
}

static int	check_before_print_philo(t_philo *philo, t_info_philo *info_philo)
{
	if (get_mutex_value(&info_philo->flag_mutex, &info_philo->flag) == -1)
		return (-1);
	if (check_philo(philo, info_philo))
	{
		set_mutex_value(&info_philo->flag_mutex, &info_philo->flag, -1);
		return (1);
	}
	return (0);
}

static void	print_philo_state(\
	t_philo *philo, t_state state)
{
	if (state == taking2)
	{
		printf("%llu %d has taken a fork\n", get_current_time(), philo->num);
		philo->last_eat_time = get_current_time();
		printf("%llu %d is eating\n", get_current_time(), philo->num);
		if (philo->info_philo->time_to_must_eat != -1)
			check_more_eat(philo, philo->info_philo);
	}
	else if (state == taking1)
		printf("%llu %d has taken a fork\n", get_current_time(), philo->num);
	else if (state == sleeping)
		printf("%llu %d is sleeping\n", get_current_time(), philo->num);
	else if (state == thinking)
		printf("%llu %d is thinking\n", get_current_time(), philo->num);
	else if (state == dying)
		printf("%llu %d died\n", get_current_time(), philo->num);
}

static void	check_more_eat(t_philo *philo, t_info_philo *info_philo)
{
	if (++(philo->time_to_eat) == info_philo->time_to_must_eat)
	{
		pthread_mutex_lock(&info_philo->more_eat_mutex);
		if (++(info_philo->more_eat) == info_philo->nbr_of_philos)
		{
			set_mutex_value(&info_philo->flag_mutex, &info_philo->flag, -1);
			print_must_eat_message();
		}
		pthread_mutex_unlock(&info_philo->more_eat_mutex);
	}
}

static void	print_must_eat_message(void)
{
	printf("%llu All philosophers ate at least times as they should.\n",
		get_current_time());
}
