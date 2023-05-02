/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:37:40 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/01 17:41:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_map_line(t_map *map, int i, int *cnt_player)
{
	int	j;

	j = 0;
	if (ft_strlen(map->data[i]) != map->width)
		return (FALSE);
	while (j < map->width)
	{
		if (map->data[i][j] == 'C')
			map->cnt_collect++;
		if (map->data[i][j] == 'E')
			map->cnt_exit++;
		if (map->data[i][j] == 'P')
			(*cnt_player)++;
		if ((i == 0 || i == map->height - 1
				|| j == 0 || j == map->width - 1)
			&& map->data[i][j] != '1')
			return (FALSE);
		j++;
	}
	return (TRUE);
}

static int	valid_map_basic(t_map *map)
{
	int	cnt_player;
	int	i;

	map->cnt_collect = 0;
	map->cnt_exit = 0;
	cnt_player = 0;
	i = 0;
	while (i < map->height)
	{
		if (valid_map_line(map, i, &cnt_player) == FALSE)
		{
			print_err("Invalid Map : check surrounded rectangle\n");
			return (FALSE);
		}
		i++;
	}
	if (map->cnt_collect == 0 || map->cnt_exit != 1 || cnt_player != 1)
	{
		print_err("Invalid Map : Check the number of elements.\n");
		return (FALSE);
	}
	return (TRUE);
}

static int	valid_map_dfs(int x, int y, t_player *player, char **visited)
{
	if (visited[y][x] == '1')
		return (0);
	if (visited[y][x] == '0' || visited[y][x] == 'P'
		|| visited[y][x] == 'E' || visited[y][x] == 'C')
	{
		if (visited[y][x] == 'E')
			(player->cnt_exit)++;
		if (visited[y][x] == 'C')
			(player->cnt_collect)++;
		visited[y][x] = '1';
		valid_map_dfs(x - 1, y, player, visited);
		valid_map_dfs(x, y - 1, player, visited);
		valid_map_dfs(x + 1, y, player, visited);
		valid_map_dfs(x, y + 1, player, visited);
		return (TRUE);
	}
	return (FALSE);
}

static int	valid_map_avail(t_map *map)
{
	t_player	player;
	char		**visited;
	int			i;

	visited = dup_strs(map->data, map->height);
	if (!visited)
	{
		print_err("Not Enough memory!\n");
		return (FALSE);
	}
	find_player(&player, map);
	player.cnt_collect = 0;
	player.cnt_exit = 0;
	valid_map_dfs(player.x, player.y, &player, visited);
	i = -1;
	while (++i < map->height)
		free(visited[i]);
	free(visited);
	if (player.cnt_collect != map->cnt_collect
		|| player.cnt_exit != map->cnt_exit)
	{
		print_err("No valid path.\n");
		return (FALSE);
	}
	return (TRUE);
}

int	valid_map(t_map *map)
{
	if (valid_map_basic(map) == FALSE
		|| valid_map_avail(map) == FALSE)
		return (FALSE);
	return (TRUE);
}
