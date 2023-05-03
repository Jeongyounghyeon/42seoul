/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:36:40 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/03 19:01:41 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**dup_strs(char **strs, int size);
int		print_err(char *comment);

char	**dup_strs(char **strs, int size)
{
	char	**res;
	int		i;

	if (!strs)
		return (0);
	res = (char **)malloc((size + 1) * sizeof(char *));
	if (!res)
	{
		print_err("Not Enough Memroy!");
		return (0);
	}
	i = -1;
	while (++i < size)
	{
		res[i] = ft_strdup(strs[i]);
		if (!res[i])
		{
			print_err("Not Enough Memory!");
			while (i >= 0)
				free(res[i--]);
			free(res);
			return (0);
		}
	}
	return (res);
}

int	print_err(char *comment)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(comment, 2);
	return (FALSE);
}
