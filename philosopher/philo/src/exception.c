/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 22:01:49 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/24 16:23:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parameter_exception(void);

void	parameter_exception(void)
{
	write(1, "The philo program requires a factor of 5~6 int numbers.\n \
1. number_of_philosophers\n \
2. time_to_die\n \
3. time_to_eat\n \
4. time_to_sleep\n \
5. number_of_times_each_philosopher_must_eat(Option)\n", 205);
	exit(1);
}
