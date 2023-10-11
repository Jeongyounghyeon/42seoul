/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:32:03 by jy_23             #+#    #+#             */
/*   Updated: 2023/10/06 16:22:26 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "map.h"
#include "bool.h"
#include "exception.h"
#include "xmem.h"

void			valid_map(t_map *map);
static void		valid_map_elements(char *elements[]);
static void		valid_map_contents(t_map *map);
static t_bool	valid_a_content(char content, t_map *map, int x, int y);

void	valid_map(t_map *map)
{
	valid_map_elements(map->elements);
	valid_map_contents(map);
	valid_closed_wall(map);
	if (map->start_x == -1 || map->start_y == -1)
		exception_handler(err_player);
}

static void	valid_map_elements(char *elements[])
{
	int	i;

	i = 0;
	while (i < NUM_OF_ELEMENT)
	{
		if (!elements[i])
		{
			exception_handler(err_ele_id);
		}
		i++;
	}
}

static void	valid_map_contents(t_map *map)
{
	int		h;
	int		w;
	char	**contents;

	h = 0;
	contents = map->contents;
	if (!contents || !*contents)
		exception_handler(err_map);
	while (contents[h])
	{
		if (!contents[h] || !*contents[h] || is_empty_line(contents[h]) == true)
			exception_handler(err_map);
		w = 0;
		while (contents[h][w])
		{
			if (valid_a_content(contents[h][w], map, w, h) == false)
				exception_handler(err_map);
			w++;
		}
		if (w > map->width)
			map->width = w;
		h++;
	}
	map->height = h;
}

static t_bool	valid_a_content(char content, t_map *map, int x, int y)
{
	if (content == '1'
		|| content == '0'
		|| content == ' ')
		return (true);
	else if (
		(content == 'E' || content == 'W' || content == 'S' || content == 'N')
		&& (map->start_x == -1 && map->start_y == -1)
	)
	{
		map->start_x = x;
		map->start_y = y;
		map->start_dir = content;
		map->contents[y][x] = '0';
		return (true);
	}
	else
		return (false);
}
