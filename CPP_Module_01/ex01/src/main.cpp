/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:04:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/13 23:17:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

static void	zombieHordeTest(int N);

int	main(void) {
	zombieHordeTest(5);
}

static void	zombieHordeTest(int N) {
	Zombie	*zombies = zombieHorde(N, "zombie");

	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete []zombies;
}

