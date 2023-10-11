/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:27:08 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/06 15:57:14 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "config.h"
#include "exception.h"

void		set_config(t_config *config, t_map *map);
static void	set_config_player(t_player *player, t_map *map);
static void	set_config_textures(t_config *config, char *elements[6]);
static void	set_config_a_texture(t_img *texture, void *mlx, char *path);
static void	set_config_key(t_key *key);

void	set_config(t_config *config, t_map *map)
{
	config->map = map->contents;
	config->f_rgb = map->f_rgb;
	config->c_rgb = map->c_rgb;
	set_config_textures(config, map->elements);
	set_config_player(&config->player, map);
	set_config_key(&config->key);
	config->rc.camera.x = config->player.dir.y * (FOV);
	config->rc.camera.y = config->player.dir.x * (-FOV);
	config->screen.img
		= mlx_new_image(config->window.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (config->screen.img == 0)
		exception_handler(err_general);
	config->screen.data = (int *)mlx_get_data_addr(config->screen.img,
			&config->screen.bpp,
			&config->screen.size_line,
			&config->screen.endian);
}

static void	set_config_textures(t_config *config, char *elements[6])
{
	t_img	*textures;
	void	*mlx;
	int		i;

	mlx = config->window.mlx;
	textures = config->textures;
	i = 0;
	while (i < 4)
	{
		set_config_a_texture(&textures[i], mlx, elements[i]);
		i++;
	}
}

static void	set_config_a_texture(t_img *texture,
				void *mlx, char *path)
{
	texture->img
		= mlx_xpm_file_to_image(mlx, path, &texture->width, &texture->height);
	if (!texture->img)
		exception_handler(err_ele_info_img);
	texture->data = (int *)mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->size_line, &texture->endian);
}

static void	set_config_player(t_player *player, t_map *map)
{
	player->pos.x = map->start_x + 0.5;
	player->pos.y = map->start_y + 0.5;
	player->map_pos.x = (int)player->pos.x;
	player->map_pos.y = (int)player->pos.y;
	if (map->start_dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (map->start_dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (map->start_dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (map->start_dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
}

static void	set_config_key(t_key *key)
{
	key->w = false;
	key->a = false;
	key->s = false;
	key->d = false;
	key->left = false;
	key->right = false;
}
