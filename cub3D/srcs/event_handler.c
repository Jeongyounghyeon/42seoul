/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:36:47 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/05 19:31:57 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "event.h"

int	exit_event_handler(int key_code, void *param)
{
	(void)key_code;
	(void)param;
	exit(0);
}

int	press_event_handler(int key_code, t_key *key)
{
	if (key_code == KEY_W)
		key->w = true;
	if (key_code == KEY_S)
		key->s = true;
	if (key_code == KEY_A)
		key->a = true;
	if (key_code == KEY_D)
		key->d = true;
	if (key_code == KEY_LEFT)
		key->left = true;
	if (key_code == KEY_RIGHT)
		key->right = true;
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int	release_event_handler(int key_code, t_key *key)
{
	if (key_code == KEY_W)
		key->w = false;
	if (key_code == KEY_S)
		key->s = false;
	if (key_code == KEY_A)
		key->a = false;
	if (key_code == KEY_D)
		key->d = false;
	if (key_code == KEY_LEFT)
		key->left = false;
	if (key_code == KEY_RIGHT)
		key->right = false;
	return (0);
}
