/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:13:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/01/07 15:17:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;
	void	*tmp;

	if (!lst || !f || !del)
		return (0);
	res = 0;
	while (lst)
	{
		tmp = f(lst->content);
		temp = ft_lstnew(tmp);
		if (!temp)
		{
			del(tmp);
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, temp);
		lst = lst->next;
	}
	return (res);
}
