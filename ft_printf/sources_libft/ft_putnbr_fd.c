/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:40:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/07 15:18:17 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static void	write_num(int n, int fd)
{
	if (n / 10)
		write_num(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		write_num(n * (-1), fd);
	}
	else
		write_num(n, fd);
}
