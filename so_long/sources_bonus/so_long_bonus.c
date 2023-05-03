/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:25:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/03 19:01:08 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		main(int argc, char **argv);
int		so_long(t_map *map);
void	clear_game(t_so_long *so_long);
int		key_input(int keycode, t_so_long *so_long);
int		exit_hook(t_so_long *so_long);

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		print_err("The parameter must be one map of the form ber.\n");
		return (0);
	}
	init_map(&map, argv[1]);
	if (!(map.data))
		return (0);
	so_long(&map);
	free_map(&map);
	return (0);
}

int	so_long(t_map *map)
{
	t_so_long	so_long;
	t_win		window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx,
			map->width * 64, map->height * 64, "so_long");
	if (init_so_long(&so_long, &window, map) == FALSE)
		key_input(53, &so_long);
	mlx_key_hook(window.win, key_input, &so_long);
	mlx_hook(window.win, 17, 0, exit_hook, &so_long);
	mlx_loop(window.mlx);
	return (0);
}

void	clear_game(t_so_long *so_long)
{
	ft_putstr_fd("Final Steps : ", 1);
	ft_putnbr_fd(++(so_long->player->cnt_move), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Congratulation : Clear game!!\n", 1);
	exit_hook(so_long);
}

int	key_input(int keycode, t_so_long *so_long)
{
	int	change;

	change = 0;
	if (keycode == 53)
		exit_hook(so_long);
	else if (keycode == 13 || keycode == 126)
		change = player_move_up(so_long);
	else if (keycode == 0 || keycode == 123)
		change = player_move_left(so_long);
	else if (keycode == 1 || keycode == 125)
		change = player_move_down(so_long);
	else if (keycode == 2 || keycode == 124)
		change = player_move_right(so_long);
	if (change)
	{
		ft_putstr_fd("steps : ", 1);
		ft_putnbr_fd(so_long->player->cnt_move, 1);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}

int	exit_hook(t_so_long *so_long)
{
	mlx_destroy_window(so_long->win->mlx, so_long->win->win);
	free(so_long->img);
	free(so_long->player);
	exit(0);
}
