/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:41:07 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/20 22:49:19 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "config.h"

int	rendering(t_config *config)
{
	update_player(config);
	raycasting(config);
	mlx_put_image_to_window(config->window.mlx,
		config->window.win, config->screen.img, 0, 0);
	return (0);
}
