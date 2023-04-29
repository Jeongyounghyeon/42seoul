/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:25:09 by youjeong          #+#    #+#             */
/*   Updated: 2023/04/29 15:31:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	make_map(t_win *window, int width, int height)
{
	t_img	image_back;

	width = 64;
	height = 64;
	image_back.img = mlx_xpm_file_to_image(window->mlx, "textures/test.xpm", &width, &height);
	image_back.addr = mlx_get_data_addr(image_back.img, &image_back.bits_per_pixel, &image_back.line_length, &image_back.endian);
	for (int i=0; i< width-2; i++) {
		for (int j=0; j< height-2; j++) {
			mlx_put_image_to_window(window->mlx, window->win, image_back.img, i * 64, j*64);
		}
	}
	return (0);
}

int	key_hook(int keycode, t_win *window)
{
	if (keycode == 53)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit(0);
	}
	return (0);
}

int	so_long(t_map *map)
{
	t_win	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx,
			map->width * 64, map->height * 64, "so_long");
	make_map(&window, map->width, map->height);
	mlx_key_hook(window.win, key_hook, &window);
	mlx_loop(window.mlx);
	return (0);
}

void	check_leak(void)
{
	system("leaks --list -- so_long");
}

int	print_err(char *comment)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(comment, 2);
	return (FALSE);
}

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
	// so_long(&map);
	atexit(check_leak);
	return (0);
}
