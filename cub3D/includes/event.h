/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:21:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/06 16:26:21 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "system.h"
# include "bool.h"

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_FORWARD 		126
# define KEY_BACKWARD		125
# define KEY_ESC			53

# define EVENT_KEY_PRESS	2
# define EVENT_KEY_RELEASE	3
# define EVENT_KEY_EXIT		17

# define MOVE_SPEED			0.02
# define ROT_SPEED			0.02
# define MARGIN				0.0000000001

# define WALL				'1'

typedef struct s_player {
	t_coord		pos;
	t_vec		dir;
	t_coord		map_pos;
}	t_player;

typedef struct s_key {
	t_bool	w;
	t_bool	a;
	t_bool	s;
	t_bool	d;
	t_bool	left;
	t_bool	right;
}t_key;

int	exit_event_handler(int key_code, void *param);
int	press_event_handler(int key_code, t_key *key);
int	release_event_handler(int key_code, t_key *key);

#endif
