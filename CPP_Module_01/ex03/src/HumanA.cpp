/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:52:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/14 20:24:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name),
													weapon(weapon) {};
HumanA::~HumanA(void) {};

std::string	HumanA::getName(void) const {
	return (this->name);
}

Weapon&		HumanA::getWeapon(void) const {
	return (this->weapon);
}

void HumanA::setName(std::string name) {
	this->name = name;
}

void	HumanA::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
};