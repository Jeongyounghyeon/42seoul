/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:23:57 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/29 15:05:41 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TRUE 1
# define FALSE 0
# define ERROR -1

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <get_next_line.h>
# include <../mlx/mlx.h>

// mlx 구조체
typedef struct s_win {
	void	*mlx;
	void	*win;
}	t_win;

// image data 구조체
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

// map 구조체
typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
	int		cnt_collect;
	int		cnt_exit;
}	t_map;

// player 구조체
typedef struct s_player
{
	int	x;
	int	y;
	int	cnt_collect;
	int	cnt_exit;
}	t_player;

int		print_err(char *comment);

// map
void	init_map(t_map *map, char *path_map);
int		valid_map(t_map *map);
void	free_map(t_map *map);

// utils
char	**dup_strs(char **strs, int size);

void	find_player(t_player *player, t_map *map);

#endif