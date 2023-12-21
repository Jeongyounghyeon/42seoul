/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Type.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:44:02 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/20 18:44:22 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef enum method {
	GET,
	POST,
	DELETE
} method;

typedef struct s_listen {
	int ip;
	int port;
} t_listen;