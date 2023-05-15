/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:21:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/17 14:02:07 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			main(void);
static void	get_sig(int sig);
static void	init_sigact(struct sigaction *act);

int	main(void)
{
	struct sigaction	act;

	ft_putstr_fd("server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	init_sigact(&act);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}

static void	get_sig(int sig)
{
	static t_cbit	cbit;
	char			bit_in;

	bit_in = 0;
	if (sig == SIGUSR1)
		bit_in = 0;
	else if (sig == SIGUSR2)
		bit_in = 1;
	else
		return ;
	cbit.c |= bit_in;
	if (cbit.bit < 7)
		cbit.c <<= 1;
	cbit.bit++;
	if (cbit.bit == 8)
	{
		write(1, &cbit.c, 1);
		cbit.c = 0;
		cbit.bit = 0;
	}
}

static void	init_sigact(struct sigaction *act)
{
	act->sa_handler = get_sig;
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGUSR1);
	sigaddset(&act->sa_mask, SIGUSR2);
	act->sa_flags = 0;
}
