/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:23:57 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/03 14:28:01 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	void	*background;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player_up;
	void	*player_left;
	void	*player_down;
	void	*player_right;
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
	int		x;
	int		y;
	int		cnt_collect;
	int		cnt_exit;
	int		cnt_move;
	char	direct;
}	t_player;

typedef struct s_so_long
{
	t_win		*win;
	t_img		*img;
	t_map		*map;
	t_player	*player;
}t_so_long;

// so_long
int		init_so_long(t_so_long *so_long, t_win *window, t_map *map);
void	clear_game(t_so_long *so_long);
void	put_img(t_so_long *so_long, char feature, int i, int j);
int		key_input(int keycode, t_so_long *so_long);

// map
void	init_map(t_map *map, char *path_map);
int		valid_map(t_map *map);
void	free_map(t_map *map);

// utils
char	**dup_strs(char **strs, int size);
int		print_err(char *comment);

// player
void	find_player(t_player *player, t_map *map);
int		player_move_up(t_so_long *so_long);
int		player_move_left(t_so_long *so_long);
int		player_move_down(t_so_long *so_long);
int		player_move_right(t_so_long *so_long);

#endif