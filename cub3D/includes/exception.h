/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:44:43 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/19 16:53:44 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_H
# define EXCEPTION_H

typedef enum e_errno
{
	err_arg = 1,
	err_cub_file,
	err_ele_id,
	err_ele_info_img,
	err_ele_info_rgb,
	err_map,
	err_wall,
	err_player,
	err_general
}	t_errno;

void	exception_handler(t_errno errno);

#endif
