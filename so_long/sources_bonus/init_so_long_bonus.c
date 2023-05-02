/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:27:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/02 22:52:03 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	put_start_img(t_so_long *so_long)
{
	t_map	*map;
	int		i;
	int		j;

	map = so_long->map;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			put_img(so_long, '0', i, j);
			put_img(so_long, map->data[i][j], i, j);
			j++;
		}
		i++;
	}
	return (0);
}

static void	init_img_unplayer(void *mlx, t_img *img)
{
	int	width;
	int	height;

	img->background = mlx_xpm_file_to_image(mlx, \
					"textures/background.xpm", &width, &height);
	img->collect = mlx_xpm_file_to_image(mlx, \
					"textures/collect.xpm", &width, &height);
	img->exit = mlx_xpm_file_to_image(mlx, \
					"textures/exit.xpm", &width, &height);
	img->wall = mlx_xpm_file_to_image(mlx, \
					"textures/wall.xpm", &width, &height);
}

static void	init_img_player(void *mlx, t_img *img)
{
	int	width;
	int	height;

	img->player_up = mlx_xpm_file_to_image(mlx, \
					"textures/player/player_up.xpm", &width, &height);
	img->player_left = mlx_xpm_file_to_image(mlx, \
					"textures/player/player_left.xpm", &width, &height);
	img->player_down = mlx_xpm_file_to_image(mlx, \
					"textures/player/player_down.xpm", &width, &height);
	img->player_right = mlx_xpm_file_to_image(mlx, \
					"textures/player/player_right.xpm", &width, &height);
}

static int	init_img(t_so_long *so_long)
{
	t_img	*img;

	so_long->img = (t_img *)malloc(1 * sizeof(t_img));
	if (!(so_long->img))
	{
		print_err("Not Enough Memory!");
		return (FALSE);
	}
	img = so_long->img;
	init_img_unplayer(so_long->win->mlx, img);
	init_img_player(so_long->win->mlx, img);
	if (!(img->background) || !(img->collect) || !(img->exit) || !(img->wall) \
		|| !(img->player_up) || !(img->player_down) \
		|| !(img->player_left) || !(img->player_right))
	{
		print_err("Not Enough Memory!");
		return (FALSE);
	}
	return (TRUE);
}

int	init_so_long(t_so_long *so_long, t_win *window, t_map *map)
{
	so_long->win = window;
	so_long->map = map;
	if (init_img(so_long) == FALSE)
		return (FALSE);
	so_long->player = (t_player *)malloc(1 * sizeof(t_player));
	if (!so_long->player)
	{
		print_err("Not enough memory!");
		return (FALSE);
	}
	find_player(so_long->player, so_long->map);
	so_long->player->cnt_collect = 0;
	so_long->player->cnt_exit = 0;
	so_long->player->cnt_move = 0;
	so_long->player->direct = 'D';
	put_start_img(so_long);
	return (TRUE);
}
