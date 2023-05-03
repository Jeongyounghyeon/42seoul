/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:42:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/03 19:01:22 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void		put_img(t_so_long *so_long, char feature, int i, int j);
static void	put_img_player(t_so_long *so_long, int i, int j);

void	put_img(t_so_long *so_long, char feature, int i, int j)
{
	mlx_put_image_to_window(so_long->win->mlx, so_long->win->win, \
							so_long->img->background, j * 64, i * 64);
	if (feature == '1')
		mlx_put_image_to_window(so_long->win->mlx, so_long->win->win, \
								so_long->img->wall, j * 64, i * 64);
	else if (feature == 'C')
		mlx_put_image_to_window(so_long->win->mlx, so_long->win->win, \
								so_long->img->collect, j * 64, i * 64);
	else if (feature == 'E')
		mlx_put_image_to_window(so_long->win->mlx, so_long->win->win, \
								so_long->img->exit, j * 64, i * 64);
	else if (feature == 'P')
		put_img_player(so_long, i, j);
}

static void	put_img_player(t_so_long *so_long, int i, int j)
{
	if (so_long->player->direct == 'U')
		mlx_put_image_to_window(so_long->win->mlx, so_long->win->win, \
								so_long->img->player_up, j * 64, i * 64);
	else if (so_long->player->direct == 'D')
		mlx_put_image_to_window(so_long->win->mlx, so_long->win->win, \
								so_long->img->player_down, j * 64, i * 64);
	else if (so_long->player->direct == 'L')
		mlx_put_image_to_window(so_long->win->mlx, so_long->win->win, \
								so_long->img->player_left, j * 64, i * 64);
	if (so_long->player->direct == 'R')
		mlx_put_image_to_window(so_long->win->mlx, so_long->win->win, \
								so_long->img->player_right, j * 64, i * 64);
}
