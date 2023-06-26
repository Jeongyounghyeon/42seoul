/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:32:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/06/12 21:04:57 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			input_handler(t_info_philo *info_philo, char **argv, int argc);
static void	input_time_to_think(t_info_philo *info_philo);
static int	valid_input(char **argv, int argc);
static int	valid_input_common(const char *str);

int	input_handler(t_info_philo *info_philo, char **argv, int argc)
{
	if (!valid_input(argv, argc))
	{
		printf("The philo program requires a factor of 5~6 int numbers.\n");
		printf("1. number_of_philosophers (At least 1)\n");
		printf("2. time_to_die (At least 1)\n");
		printf("3. time_to_eat (At least 1)\n");
		printf("4. time_to_sleep (At least 1)\n");
		printf("5. time_to_must_eat(Option; At least 1)\n");
		return (FALSE);
	}
	info_philo->nbr_of_philos = ft_atoi(argv[1]);
	info_philo->time_to_die = (t_ms)ft_atoi(argv[2]);
	info_philo->time_to_eat = (t_ms)ft_atoi(argv[3]);
	info_philo->time_to_sleep = (t_ms)ft_atoi(argv[4]);
	input_time_to_think(info_philo);
	if (argc == 5)
		info_philo->time_to_must_eat = -1;
	else
		info_philo->time_to_must_eat = ft_atoi(argv[5]);
	return (TRUE);
}

static void	input_time_to_think(t_info_philo *info_philo)
{
	info_philo->time_to_think = 0;
	if ((info_philo->nbr_of_philos % 2 != 0)
		&& (2 * info_philo->time_to_eat > info_philo->time_to_sleep))
		info_philo->time_to_think = \
			2 * info_philo->time_to_eat - info_philo->time_to_sleep;
	if ((info_philo->nbr_of_philos % 2 == 0)
		&& (info_philo->time_to_eat > info_philo->time_to_sleep))
		info_philo->time_to_think = \
			info_philo->time_to_eat - info_philo->time_to_sleep;
}

static int	valid_input(char **argv, int argc)
{
	int	i;

	if (!(argc >= 5 && argc <= 6))
		return (FALSE);
	i = 0;
	while (++i < argc)
	{
		if (!valid_input_common(argv[i]))
			return (FALSE);
	}
	i = 0;
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (FALSE);
	}
	return (TRUE);
}

static int	valid_input_common(const char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && !(*str == '+'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}
