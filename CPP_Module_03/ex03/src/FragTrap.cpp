/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:44:11 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 18:40:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap's default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << "'s constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref) {
	std::cout << "FragTrap's copy constructor called" << std::endl;
	*this = ref;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << "'s destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& ref) {
	std::cout << "FragTrap's operator = called" << std::endl;
	if (this == &ref)
		return *this;

	ClapTrap::operator=(ref);
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (!this->hitPoints || !this->energyPoints)
		std::cout << "FragTrap " << this->name << " failed to attack " << target << "! (attack)" << std::endl;
	else {
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << ": Please give me a high five" << std::endl;
}