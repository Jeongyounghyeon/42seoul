/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:21:22 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/17 13:45:45 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			main(int argc, char **argv);
static void	send_str(int pid, char *str);
static void	send_sig(int pid, char *str);

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		exit(1);
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) != 0)
	{
		ft_putstr_fd("Signal transmission failed.", 1);
		exit(1);
	}
	send_str(pid, argv[2]);
	return (0);
}

static void	send_str(int pid, char *str)
{
	char	*send;

	send = ft_strjoin(str, "\n");
	if (send == NULL)
	{
		ft_putstr_fd("Not enough memroy!", 1);
		exit(1);
	}
	send_sig(pid, send);
	free(send);
	exit(0);
}

static void	send_sig(int pid, char *str)
{
	size_t	ind_str;
	size_t	ind_bit;
	char	tmp_bit;
	size_t	len_str;

	len_str = ft_strlen(str);
	ind_str = 0;
	while (ind_str < len_str)
	{
		ind_bit = 0;
		while (ind_bit < 8)
		{
			tmp_bit = (str[ind_str] >> (7 - ind_bit)) & 1;
			if (tmp_bit == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(30);
			ind_bit++;
		}
		ind_str++;
	}
}
