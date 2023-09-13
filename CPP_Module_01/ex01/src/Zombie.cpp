/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:30:15 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/12 18:41:39 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "noname" << ": " << "I am created!!!" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
	std::cout << this->name << ": " << "I am created!!!" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << this->name << ": " << "I am died!!!" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void) const {
	return (this->name);
}

void	Zombie::setName(std::string name) {
	this->name = name;
}