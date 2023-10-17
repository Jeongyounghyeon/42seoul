/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:38:45 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 18:40:11 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap's default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << "'s constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref) {
	std::cout << "ScavTrap's copy constructor called" << std::endl;
	*this = ref;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << "'s destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref) {
	std::cout << "ScavTrap's operator = called" << std::endl;
	if (this == &ref)
		return *this;

	ClapTrap::operator=(ref);
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (!this->hitPoints || !this->energyPoints)
		std::cout << "ScavTrap " << this->name << " failed to attack " << target << "! (attack)" << std::endl;
	else {
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}