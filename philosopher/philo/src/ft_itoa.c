/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:31:22 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/27 16:01:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char		*ft_itoa(int n);
static void	mk_str(long long num, char *res, size_t idx);
static int	len_digit(long long num);

char	*ft_itoa(int n)
{
	char		*res;
	long long	num;
	int			isMinus;
	int			len;

	isMinus = 0;
	num = (long long)n;
	if (n < 0)
	{
		isMinus = 1;
		num = -num;
	}
	len = len_digit(num);
	res = (char *)malloc((isMinus + len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	res[isMinus + len] = 0;
	mk_str(num, res, (size_t)(isMinus + len - 1));
	if (isMinus)
		res[0] = '-';
	return (res);
}

static void	mk_str(long long num, char *res, size_t idx)
{
	while (num / 10)
	{
		res[idx] = (num % 10) + '0';
		idx--;
		num /= 10;
	}
	res[idx] = num + '0';
}

static int	len_digit(long long num)
{
	int	res;

	res = 1;
	while (num / 10)
	{
		res++;
		num /= 10;
	}
	return (res);
}
