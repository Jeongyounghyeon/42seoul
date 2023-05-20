/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:21:13 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/20 15:01:32 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

# include <unistd.h>
# include <signal.h>
# include "libft.h"

typedef struct s_data
{
	struct sigaction	act;
	pid_t				pid;
	char				*msg;
}t_data;

void	send_sig(pid_t pid, int sig);

#endif