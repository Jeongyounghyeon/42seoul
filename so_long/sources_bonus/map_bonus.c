/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:05:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/05/02 22:52:10 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static t_list	*fd_to_list(int fd)
{
	t_list	*res;
	char	*pstr;

	if (fd < 0)
		return (0);
	pstr = get_next_line(fd);
	if (!pstr)
		print_err("There isn't any content!\n");
	res = 0;
	while (pstr)
	{
		if (pstr[ft_strlen(pstr) - 1] == '\n')
			pstr[ft_strlen(pstr) - 1] = 0;
		ft_lstadd_back(&res, ft_lstnew(pstr));
		if (ft_lstlast(res)->content != pstr)
		{
			print_err("Not Enough Memory!\n");
			ft_lstclear(&res, free);
			return (0);
		}
		pstr = get_next_line(fd);
	}
	return (res);
}

static void	list_to_map(t_list *lst, t_map *map)
{
	t_list	*plst;
	int		i;

	i = 0;
	plst = lst;
	while (i < map->height)
	{
		map->data[i] = plst->content;
		plst = plst->next;
		i++;
	}
	map->data[i] = 0;
}

static void	make_map(t_map *map, int fd)
{
	t_list	*lst;

	lst = fd_to_list(fd);
	if (!lst)
		return ;
	map->width = ft_strlen(ft_lstlast(lst)->content);
	map->height = ft_lstsize(lst);
	if (!(map->height))
		return ;
	map->data = (char **)malloc((map->height + 1) * sizeof(char *));
	if (!(map->data))
	{
		print_err("Not Enough Memory!\n");
		ft_lstclear(&lst, free);
		return ;
	}
	list_to_map(lst, map);
	ft_lstclear(&lst, 0);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map || map->height == 0)
		return ;
	i = 0;
	while (i <= map->height)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	map->data = 0;
}

void	init_map(t_map *map, char *path_map)
{
	int	fd;

	map->data = 0;
	fd = open(path_map, O_RDONLY);
	make_map(map, fd);
	close(fd);
	if (map->data == 0)
		return ;
	if (valid_map(map) == FALSE)
		free_map(map);
}
