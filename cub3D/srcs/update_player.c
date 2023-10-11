/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:25:10 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/06 16:27:41 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

void		update_player(t_config *config);
static void	hr_move_h_update(char **map, \
				t_player *player, int new_dir_x, int new_dir_y);
static void	vt_move_update(char **map, \
				t_player *player, int new_dir_x, int new_dir_y);
static void	rotate_update(t_config *config, double radian);
static void	rotate_vector(t_vec *vector, double theta);

void	update_player(t_config *config)
{
	if (config->key.w == true)
		hr_move_h_update(config->map, &config->player, 1, 1);
	if (config->key.s == true)
		hr_move_h_update(config->map, &config->player, -1, -1);
	if (config->key.a == true)
		vt_move_update(config->map, &config->player, 1, -1);
	if (config->key.d == true)
		vt_move_update(config->map, &config->player, -1, 1);
	if (config->key.left == true)
		rotate_update(config, ROT_SPEED);
	if (config->key.right == true)
		rotate_update(config, -ROT_SPEED);
}

static void	hr_move_h_update(char **map,
			t_player *player, int new_dir_x, int new_dir_y)
{
	t_coord		*pos;
	double		dir_x;
	double		dir_y;

	pos = &player->pos;
	dir_x = player->dir.x * new_dir_x;
	dir_y = player->dir.y * new_dir_y;
	if (map[(int)(pos->y + dir_y * (MOVE_SPEED + MARGIN))][(int)pos->x] != WALL)
		pos->y += dir_y * MOVE_SPEED;
	if (map[(int)pos->y][(int)(pos->x + dir_x * (MOVE_SPEED + MARGIN))] != WALL)
		pos->x += dir_x * MOVE_SPEED;
}

static void	vt_move_update(char **map,
			t_player *player, int new_dir_x, int new_dir_y)
{
	t_coord		*pos;
	double		dir_x;
	double		dir_y;

	pos = &player->pos;
	dir_x = player->dir.x * new_dir_x;
	dir_y = player->dir.y * new_dir_y;
	if (map[(int)(pos->y + dir_x * (MOVE_SPEED + MARGIN))][(int)pos->x] != WALL)
		pos->y += dir_x * MOVE_SPEED;
	if (map[(int)pos->y][(int)(pos->x + dir_y * (MOVE_SPEED + MARGIN))] != WALL)
		pos->x += dir_y * MOVE_SPEED;
}

static void	rotate_update(t_config *config, double radian)
{
	rotate_vector(&config->player.dir, radian);
	rotate_vector(&config->rc.camera, radian);
}

static void	rotate_vector(t_vec *vector, double theta)
{
	double	vector_x;

	vector_x = vector->x;
	vector->x = vector->x * cos(theta) - vector->y * sin(theta);
	vector->y = vector_x * sin(theta) + vector->y * cos(theta);
}
