/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:51:59 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/25 23:20:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

HumanB::~HumanB(void) {}

std::string	HumanB::getName(void) const {
	return this->name;
}

Weapon*	HumanB::getWeapon(void) const {
	return this->weapon;
}

void HumanB::setName(std::string name) {
	this->name = name;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}