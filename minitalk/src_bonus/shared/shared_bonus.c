/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:21:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/20 15:23:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_bonus.h"

void	send_sig(pid_t pid, int sig)
{
	if (kill(pid, sig) != 0)
	{
		ft_putstr_fd("Connection with server failed.\n", 1);
		exit(1);
	}
	else
		usleep(100);
}
