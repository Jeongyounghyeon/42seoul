/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:25:51 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/14 20:17:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N < 1)
		return NULL;

	Zombie*	zombies = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		std::stringstream	ss;

		ss << i;
		zombies[i].setName(name + ss.str());
	}

	return zombies;
}