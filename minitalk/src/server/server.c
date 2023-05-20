/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:21:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/20 15:05:09 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		main(int argc, char **argv);
void	connect_with_client(int sig, siginfo_t *siginfo, void *param);
void	receive_message(int sig, siginfo_t *siginfo, void *param);
char	*ft_charjoin(char *str, char ch);

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("The program that does not require a factor.\n", 1);
		exit(0);
	}
	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	g_data.act.sa_flags = SA_SIGINFO;
	g_data.act.sa_sigaction = connect_with_client;
	sigemptyset(&g_data.act.sa_mask);
	sigaction(SIGUSR1, &g_data.act, 0);
	sigaction(SIGUSR2, &g_data.act, 0);
	while (1)
		pause();
	return (0);
}

void	connect_with_client(int sig, siginfo_t *siginfo, void *param)
{
	(void)param;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		ft_putnbr_fd(siginfo->si_pid, 1);
		ft_putstr_fd("(sending pid) : ", 1);
		g_data.pid = siginfo->si_pid;
		g_data.msg = ft_strdup("");
		g_data.act.sa_sigaction = receive_message;
		sigaction(SIGUSR1, &g_data.act, NULL);
		sigaction(SIGUSR2, &g_data.act, NULL);
		send_sig(g_data.pid, sig);
	}
	else
	{
		ft_putstr_fd("CONNECTION FAILED\n", 1);
		exit(1);
	}
}

void	receive_message(int sig, siginfo_t *siginfo, void *param)
{
	static int	bit = 8;
	static char	c = 0;

	(void)param;
	if (sig == SIGUSR1)
		c += 1 << --bit;
	else if (sig == SIGUSR2)
		--bit;
	if (bit == 0)
	{
		if (c != 0)
			g_data.msg = ft_charjoin(g_data.msg, c);
		else
		{
			ft_putstr_fd(g_data.msg, 1);
			ft_putchar_fd('\n', 1);
			free(g_data.msg);
			g_data.act.sa_sigaction = connect_with_client;
			sigaction(SIGUSR1, &g_data.act, NULL);
			sigaction(SIGUSR2, &g_data.act, NULL);
			send_sig(siginfo->si_pid, SIGUSR2);
		}
		bit = 8;
		c = 0;
	}
}

char	*ft_charjoin(char *str, char ch)
{
	size_t	str_len;
	char	*ptr;
	int		i;

	if (!str)
		return (NULL);
	str_len = ft_strlen((char *)str);
	ptr = malloc(str_len + sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i++] = ch;
	ptr[i] = 0;
	free(str);
	return (ptr);
}
