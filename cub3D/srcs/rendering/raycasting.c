/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:29:26 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/20 22:12:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

void			raycasting(t_config *config);
static void		init_ray(t_ray *ray,
					t_player *player, t_vec camera, double camera_x);
static double	calc_delta_dist(double ray_dir);
static int		get_hit_side(t_raycasting *rc, t_player *player, char **map);

void	raycasting(t_config *config)
{
	int				x;
	int				side;
	double			perp_wall_dist;
	t_raycasting	*rc;
	t_player		*player;

	x = 0;
	rc = &config->rc;
	player = &config->player;
	while (x < WINDOW_WIDTH)
	{
		config->player.map_pos.x = (int)config->player.pos.x;
		config->player.map_pos.y = (int)config->player.pos.y;
		init_ray(&rc->ray, player,
			rc->camera, (2 * x / (double)WINDOW_WIDTH - 1));
		side = get_hit_side(rc, player, config->map);
		if (side == 0)
			perp_wall_dist = rc->ray.side_dist.x - rc->ray.delta_dist.x;
		else
			perp_wall_dist = rc->ray.side_dist.y - rc->ray.delta_dist.y;
		fill_screen_data(config, x, perp_wall_dist, side);
		x++;
	}
}

static double	calc_delta_dist(double ray_dir)
{
	if (ray_dir == 0)
		return (1e30);
	else
		return (fabs(1 / ray_dir));
}

static void	init_ray(t_ray *ray,
				t_player *pl, t_vec camera, double camera_x)
{
	ray->ray_dir.x = pl->dir.x + (camera.x * camera_x);
	ray->ray_dir.y = pl->dir.y + (camera.y * camera_x);
	ray->delta_dist.x = calc_delta_dist(ray->ray_dir.x);
	ray->delta_dist.y = calc_delta_dist(ray->ray_dir.y);
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pl->pos.x - pl->map_pos.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (pl->map_pos.x + 1 - pl->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pl->pos.y - pl->map_pos.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (pl->map_pos.y + 1 - pl->pos.y) * ray->delta_dist.y;
	}
}

static int	get_hit_side(t_raycasting *rc, t_player *player, char **map)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (rc->ray.side_dist.x < rc->ray.side_dist.y)
		{
			rc->ray.side_dist.x += rc->ray.delta_dist.x;
			player->map_pos.x += rc->ray.step.x;
			side = 0;
		}
		else
		{
			rc->ray.side_dist.y += rc->ray.delta_dist.y;
			player->map_pos.y += rc->ray.step.y;
			side = 1;
		}
		if (map[(int)player->map_pos.y][(int)player->map_pos.x] == WALL)
			hit = 1;
	}
	return (side);
}
