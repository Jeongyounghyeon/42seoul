/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:21:22 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/20 15:18:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		main(int argc, char **argv);
void	connect_with_server(int sig, siginfo_t *siginfo, void *param);
void	send_message(void);
void	feedback_message(int sig, siginfo_t *siginfo, void *param);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Please enter pid and message as argument.", 1);
		exit(1);
	}
	g_data.act.sa_flags = SA_SIGINFO;
	g_data.act.sa_sigaction = connect_with_server;
	sigemptyset(&g_data.act.sa_mask);
	sigaction(SIGUSR1, &g_data.act, 0);
	sigaction(SIGUSR2, &g_data.act, 0);
	g_data.pid = ft_atoi(argv[1]);
	g_data.msg = argv[2];
	send_sig(g_data.pid, SIGUSR1);
	pause();
	return (0);
}

void	connect_with_server(int sig, siginfo_t *siginfo, void *param)
{
	(void)siginfo;
	(void)param;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Successful connection with server!\n", 1);
		g_data.act.sa_sigaction = feedback_message;
		sigaction(SIGUSR1, &g_data.act, 0);
		sigaction(SIGUSR2, &g_data.act, 0);
		send_message();
		return ;
	}
	else if (sig == SIGUSR2)
		ft_putstr_fd("Failed connection with server!\n", 1);
	else
		ft_putstr_fd("Invalid SIGNAL\n", 1);
	exit(1);
}

void	send_message(void)
{
	static int	i = 0;
	static int	bit = 8;

	while (g_data.msg[i] != 0)
	{
		while (--bit >= 0)
		{
			if ((g_data.msg[i] >> bit) & 1)
				send_sig(g_data.pid, SIGUSR1);
			else
				send_sig(g_data.pid, SIGUSR2);
		}
		bit = 8;
		i++;
	}
	if (g_data.msg[i] == 0)
	{
		while (bit-- > 0)
			send_sig(g_data.pid, SIGUSR2);
		pause();
	}
}

void	feedback_message(int sig, siginfo_t *siginfo, void *param)
{
	(void)siginfo;
	(void)param;
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("Successful send message at server!\n", 1);
		exit(0);
	}
	else
	{
		ft_putstr_fd("Failed to send message!\n", 1);
		exit(1);
	}
}
