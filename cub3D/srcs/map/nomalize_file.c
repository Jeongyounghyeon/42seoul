/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nomalize_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:43:53 by jy_23             #+#    #+#             */
/*   Updated: 2023/10/10 11:47:20 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "map.h"
#include "get_next_line.h"
#include "bool.h"

t_list			*nomalize_file(t_list *lst_4_map);
static void		lst_remove(t_list **pre, t_list **curr);

t_list	*nomalize_file(t_list *lst_4_map)
{
	t_list	*iter;
	t_list	*pre;
	int		not_empty_line_cnt;

	not_empty_line_cnt = 0;
	while (lst_4_map && is_empty_line(lst_4_map->content) == true)
		lst_4_map = lst_4_map->next;
	iter = lst_4_map;
	while (iter && not_empty_line_cnt <= NUM_OF_ELEMENT)
	{
		if (is_empty_line(iter->content) == true)
			lst_remove(&pre, &iter);
		else
			not_empty_line_cnt++;
		pre = iter;
		iter = iter->next;
	}
	return (lst_4_map);
}

static void	lst_remove(t_list **pre, t_list **curr)
{
	t_list	*del;

	(*pre)->next = (*curr)->next;
	del = *curr;
	*curr = *pre;
	ft_lstdelone(del, free);
}
