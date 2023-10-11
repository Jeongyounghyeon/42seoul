/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:33:14 by jy_23             #+#    #+#             */
/*   Updated: 2023/10/06 16:09:46 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "map.h"
#include "xmem.h"

void			parse_map(t_map *map, t_list *lst_4_map);
static void		parse_map_elements(char **elements, t_list **p_lst_4_map);
static char		**parse_map_a_element(char *str);
static t_ele_id	get_element_id(char *id_str);
static void		parse_map_contents(char ***contents, t_list *lst_4_map);

void	parse_map(t_map *map, t_list *lst_4_map)
{
	t_list	*iter;

	iter = lst_4_map;
	parse_map_elements(map->elements, &iter);
	parse_map_contents(&map->contents, iter);
	map->start_x = -1;
	map->start_y = -1;
}

static void	parse_map_elements(char **elements, t_list **p_lst_4_map)
{
	t_list		*iter;
	char		**a_element;
	int			idx;
	t_ele_id	ele_id;

	idx = 0;
	iter = *p_lst_4_map;
	while (idx < NUM_OF_ELEMENT && iter)
	{
		a_element = parse_map_a_element(iter->content);
		if (a_element)
		{
			ele_id = get_element_id(a_element[0]);
			if (ele_id != id_invalid)
				elements[ele_id]
					= xsubstr(a_element[1], 0, ft_strlen(a_element[1]) - 1);
			free_vector_arr(a_element);
		}
		idx++;
		iter = iter->next;
	}
	*p_lst_4_map = iter;
}

static char	**parse_map_a_element(char *str)
{
	char	**element;
	int		idx;

	idx = 0;
	element = xsplit(str, ' ');
	while (element[idx])
		idx++;
	if (idx != 2)
	{
		free_vector_arr(element);
		return (0);
	}
	else
	{
		return (element);
	}
}

static t_ele_id	get_element_id(char *id_str)
{
	if (!ft_strncmp("NO\0", id_str, 3))
		return (id_no);
	else if (!ft_strncmp("SO\0", id_str, 3))
		return (id_so);
	else if (!ft_strncmp("EA\0", id_str, 3))
		return (id_ea);
	else if (!ft_strncmp("WE\0", id_str, 3))
		return (id_we);
	else if (!ft_strncmp("F\0", id_str, 2))
		return (id_f);
	else if (!ft_strncmp("C\0", id_str, 2))
		return (id_c);
	else
		return (id_invalid);
}

static void	parse_map_contents(char ***p_contents, t_list *lst_4_map)
{
	int		i;
	int		size;
	char	**contents;
	t_list	*iter;

	iter = lst_4_map;
	size = ft_lstsize(lst_4_map);
	contents = xmalloc(sizeof(char *) * (size + 1));
	ft_memset(contents, 0, sizeof(char *));
	contents[size] = 0;
	i = 0;
	while (iter)
	{
		contents[i++] = xsubstr(iter->content, 0, ft_strlen(iter->content) - 1);
		iter = iter->next;
	}
	*p_contents = contents;
}
