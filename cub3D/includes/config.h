/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/21 14:05:54 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "window.h"
# include "event.h"
# include "render.h"
# include "map.h"

typedef struct s_config	t_config;

typedef struct s_config {
	t_win					window;
	t_img					screen;
	t_img					textures[4];
	t_player				player;
	t_raycasting			rc;
	char					**map;
	t_key					key;
	unsigned long long		f_rgb;
	unsigned long long		c_rgb;
}	t_config;

void	set_config(t_config *config, t_map *map);

int		rendering(t_config *config);
void	raycasting(t_config *config);
void	update_player(t_config *config);
void	fill_screen_data(t_config *config,
			int x, double per_wall_distance, int side);

#endif
