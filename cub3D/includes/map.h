/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:59:25 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/13 17:50:19 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "bool.h"

# define NUM_OF_ELEMENT 6

typedef struct s_map	t_map;

typedef enum e_ele_id
{
	id_invalid = -1,
	id_no,
	id_so,
	id_we,
	id_ea,
	id_f,
	id_c
}t_ele_id;

typedef struct s_map
{
	char					**contents;
	char					*elements[6];
	unsigned long long		f_rgb;
	unsigned long long		c_rgb;
	int						width;
	int						height;
	int						start_x;
	int						start_y;
	int						start_dir;
}	t_map;

t_map	*create_map(char *file);
void	valid_extension(char *file);
void	read_file(t_list **head, char *file);
t_list	*nomalize_file(t_list *lst_4_map);
void	parse_map(t_map *map, t_list *lst_4_map);
void	valid_map(t_map *map);
void	valid_closed_wall(t_map *map);
void	parse_rgb(t_map *map);

t_bool	is_empty_line(char *line);

#endif
