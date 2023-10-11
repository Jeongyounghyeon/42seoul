/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:25:50 by jy_23             #+#    #+#             */
/*   Updated: 2023/10/06 16:25:03 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "map.h"
#include "exception.h"
#include "xmem.h"

void						parse_rgb(t_map *map);
static unsigned long long	parse_r_g_b(char *rgb);
static int					valid_r_g_b(char *rgb);
static int					valid_range(int value);

void	parse_rgb(t_map *map)
{
	if (map->elements[id_f])
		map->f_rgb = parse_r_g_b(map->elements[id_f]);
	if (map->elements[id_c])
		map->c_rgb = parse_r_g_b(map->elements[id_c]);
}

static unsigned long long	parse_r_g_b(char *rgb)
{
	int						i;
	char					**sep_rgb;
	unsigned long long		numeric_rgb[3];
	unsigned long long		hex_rgb;

	sep_rgb = xsplit(rgb, ',');
	i = 0;
	while (sep_rgb[i])
		i++;
	if (i != 3)
		exception_handler(err_ele_info_rgb);
	i = 0;
	while (i < 3)
	{
		numeric_rgb[i] = valid_r_g_b(sep_rgb[i]);
		i++;
	}
	hex_rgb = ((numeric_rgb[0] & 0xff) << 16) + ((numeric_rgb[1] & 0xff) << 8)
		+ ((numeric_rgb[2] & 0xff));
	free_vector_arr(sep_rgb);
	return (hex_rgb);
}

static int	valid_r_g_b(char *rgb)
{
	int	i;

	if (ft_strlen(rgb) > 3)
		exception_handler(err_ele_info_rgb);
	else
	{
		i = 0;
		while (rgb[i])
		{
			if (!ft_isdigit(rgb[i]))
				exception_handler(err_ele_info_rgb);
			i++;
		}
	}
	return (valid_range(ft_atoi(rgb)));
}

static int	valid_range(int value)
{
	if (value < 0 || value > 255)
	{
		exception_handler(err_ele_info_rgb);
		return (-1);
	}
	else
		return (value);
}
