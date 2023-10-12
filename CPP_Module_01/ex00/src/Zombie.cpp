/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:30:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/12 13:06:24 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
	std::cout << this->name << ": " << "constructor called." << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << this->name << ": " << "destructor called." << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void) const {
	return this->name;
}

void	Zombie::setName(std::string name) {
	this->name = name;
}