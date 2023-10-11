/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jy_23 <jy_23@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:07:21 by jy_23             #+#    #+#             */
/*   Updated: 2023/09/20 19:45:29 by jy_23            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define FOV 0.66

# include "system.h"

typedef struct s_ray
{
	t_vec		ray_dir;
	t_vec		side_dist;
	t_vec		delta_dist;
	t_coord		step;
}	t_ray;

typedef struct s_raycasting
{
	t_vec		camera;
	t_ray		ray;
}	t_raycasting;

#endif
