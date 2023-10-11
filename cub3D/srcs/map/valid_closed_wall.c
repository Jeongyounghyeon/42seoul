/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_closed_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:00:17 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/20 19:41:30 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "map.h"
#include "bool.h"
#include "exception.h"

void			valid_closed_wall(t_map *map);
static t_bool	valid_closed_wall_internal(char **contents,
					int *lens_4_compare, int w, int h);
static t_bool	valid_based_space(char **contents, int w, int h);
static t_bool	valid_based_blank(char **contents,
					int w, int h, int compare_len);

void	valid_closed_wall(t_map *map)
{
	int	h;
	int	w;
	int	len_set_4_comp[3];

	h = 0;
	len_set_4_comp[1] = ft_strlen(map->contents[0]);
	while (map->contents[h])
	{
		if (h < map->height - 1)
			len_set_4_comp[2] = ft_strlen(map->contents[h + 1]);
		w = 0;
		while (map->contents[h][w])
		{
			if (valid_closed_wall_internal(map->contents,
					len_set_4_comp, w, h) == false)
				exception_handler(err_wall);
			w++;
		}
		len_set_4_comp[0] = len_set_4_comp[1];
		len_set_4_comp[1] = len_set_4_comp[2];
		h++;
	}
}

static t_bool	valid_closed_wall_internal(char **contents,
					int *len_set_4_comp, int w, int h)
{
	int	ignore_len;

	ignore_len = 2147483647;
	if (contents[h][w] == '0')
	{
		if (valid_based_space(contents, w + 1, h)
			&& valid_based_space(contents, w - 1, h)
			&& valid_based_space(contents, w, h + 1)
			&& valid_based_space(contents, w, h - 1))
			return (true);
		else
			return (false);
	}
	else if (contents[h][w] == ' ')
	{
		if (valid_based_blank(contents, w + 1, h, ignore_len)
			&& valid_based_blank(contents, w - 1, h, ignore_len)
			&& valid_based_blank(contents, w, h + 1, len_set_4_comp[2])
			&& valid_based_blank(contents, w, h - 1, len_set_4_comp[0]))
			return (true);
		else
			return (false);
	}
	else
		return (true);
}

static t_bool	valid_based_space(char **contents, int w, int h)
{
	if (w == -1 || h == -1)
	{
		return (false);
	}
	else if (contents[h] == 0 || contents[h][w] == 0 || contents[h][w] == ' ')
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

static t_bool	valid_based_blank(char **contents,
					int w, int h, int compare_len)
{
	if (w == -1 || h == -1 || w > compare_len)
	{
		return (true);
	}
	else if (contents[h] == 0 || contents[h][w] == 0)
	{
		return (true);
	}
	else if (contents[h][w] == '0')
	{
		return (false);
	}
	else
	{
		return (true);
	}
}
