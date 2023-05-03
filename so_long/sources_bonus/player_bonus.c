/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:39:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/03 19:00:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_player(t_player *player, t_map *map);
int		player_move_up(t_so_long *so_long);
int		player_move_left(t_so_long *so_long);
int		player_move_down(t_so_long *so_long);
int		player_move_right(t_so_long *so_long);

void	find_player(t_player *player, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
}

int	player_move_up(t_so_long *so_long)
{
	t_player	*player;
	char		**map;

	map = so_long->map->data;
	player = so_long->player;
	if (player->y == 0 || map[(player->y) - 1][player->x] == '1')
		return (0);
	else if (map[(player->y) - 1][player->x] == 'E')
	{
		if (player->cnt_collect == so_long->map->cnt_collect)
			clear_game(so_long);
		else
			return (0);
	}
	else if (map[(player->y) - 1][player->x] == 'C')
		(player->cnt_collect)++;
	player->direct = 'U';
	put_img(so_long, '0', player->y, player->x);
	put_img(so_long, 'P', (player->y) - 1, player->x);
	map[player->y][player->x] = '0';
	map[(player->y) - 1][player->x] = 'P';
	player->y = (player->y) - 1;
	(player->cnt_move)++;
	return (1);
}

int	player_move_left(t_so_long *so_long)
{
	t_player	*player;
	char		**map;

	map = so_long->map->data;
	player = so_long->player;
	if (player->y == 0 || map[player->y][(player->x) - 1] == '1')
		return (0);
	else if (map[player->y][(player->x) - 1] == 'E')
	{
		if (player->cnt_collect == so_long->map->cnt_collect)
			clear_game(so_long);
		else
			return (0);
	}
	else if (map[player->y][(player->x) - 1] == 'C')
		(player->cnt_collect)++;
	player->direct = 'L';
	put_img(so_long, '0', player->y, player->x);
	put_img(so_long, 'P', player->y, (player->x) - 1);
	map[player->y][player->x] = '0';
	map[player->y][(player->x) - 1] = 'P';
	player->x = (player->x) - 1;
	(player->cnt_move)++;
	return (1);
}

int	player_move_down(t_so_long *so_long)
{
	t_player	*player;
	char		**map;

	map = so_long->map->data;
	player = so_long->player;
	if (player->y == 0 || map[(player->y) + 1][player->x] == '1')
		return (0);
	else if (map[(player->y) + 1][player->x] == 'E')
	{
		if (player->cnt_collect == so_long->map->cnt_collect)
			clear_game(so_long);
		else
			return (0);
	}
	else if (map[(player->y) + 1][player->x] == 'C')
		(player->cnt_collect)++;
	player->direct = 'D';
	put_img(so_long, '0', player->y, player->x);
	put_img(so_long, 'P', (player->y) + 1, player->x);
	map[player->y][player->x] = '0';
	map[(player->y) + 1][player->x] = 'P';
	player->y = (player->y) + 1;
	(player->cnt_move)++;
	return (1);
}

int	player_move_right(t_so_long *so_long)
{
	t_player	*player;
	char		**map;

	map = so_long->map->data;
	player = so_long->player;
	if (map[player->y][(player->x) + 1] == '1')
		return (0);
	else if (map[player->y][(player->x) + 1] == 'E')
	{
		if (player->cnt_collect == so_long->map->cnt_collect)
			clear_game(so_long);
		else
			return (0);
	}
	else if (map[player->y][(player->x) + 1] == 'C')
		(player->cnt_collect)++;
	player->direct = 'R';
	put_img(so_long, '0', player->y, player->x);
	put_img(so_long, 'P', player->y, (player->x) + 1);
	map[player->y][player->x] = '0';
	map[player->y][(player->x) + 1] = 'P';
	player->x = (player->x) + 1;
	(player->cnt_move)++;
	return (1);
}
