/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:04:33 by youjeong          #+#    #+#             */
/*   Updated: 2022/12/28 21:49:50 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*rmlst;
	t_list	*plst;

	plst = *lst;
	while (plst)
	{
		rmlst = plst;
		plst = plst->next;
		del(rmlst->content);
		free(rmlst);
	}
	*lst = 0;
}
