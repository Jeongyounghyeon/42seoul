/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:50:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/07/07 19:01:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../libft/includes/libft.h"

t_token_list	*get_token_list(const char *str);

t_token_list	*get_token_list(const char *str)
{
	t_token_list	*lst_origin;
	t_token_list	*lst_cleaned;

	lst_origin = get_origin_word_list(str);
	if (!lst_origin)
		return (0);
	lst_cleaned = (t_token_list *)malloc(1 * sizeof(t_token_list));
	if (!lst_cleaned)
	{
		free_token_list(lst_origin);
		return (0);
	}
	init_token_list(lst_cleaned);
	if (origin_list_to_cleand_list(lst_origin, lst_cleaned) == -1)
	{
		free_token_list(lst_cleaned);
		lst_cleaned = 0;
	}
	free(lst_origin);
	return (lst_cleaned);
}
