/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:04:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/12 00:37:52 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	stack("stack_localVariable");
	Zombie	*heap = newZombie("heap");

	randomChump("stack_randomChump");
	stack.announce();
	heap->announce();
	// delete heap;
	heap = 0;
	return (0);
}