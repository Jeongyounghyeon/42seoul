/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmem.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:56:02 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/20 19:45:03 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMEM_H
# define XMEM_H

# include <unistd.h>

void	*xmalloc(size_t bytes);
char	*xtrim(const char *s1, const char *set);
char	*xsubstr(const char *s, unsigned int start, size_t len);
char	**xsplit(const char *s, char c);
void	free_vector_arr(char **arr);

#endif
