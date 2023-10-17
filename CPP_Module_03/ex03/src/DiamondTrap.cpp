/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:58:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 21:48:26 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(),
							ScavTrap(), 
							FragTrap(),
							name("") {
	std::cout << "ClapTrap's default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"),
												ScavTrap(name + "_clap_name"),
												FragTrap(name + "_clap_name"),
												name(name) {
	std::cout << "DiamondTrap " << this->name << "'s constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ClapTrap(ref),
													ScavTrap(ref),
													FragTrap(ref) {
	std::cout << "DiamondTrap's copy constructor called" << std::endl;
	*this = ref;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << "'s destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref) {
	std::cout << "DiamondTrap's operator = called" << std::endl;
	if (this == &ref)
		return *this;

	ScavTrap::operator=(ref);
	FragTrap::operator=(ref);
	this->name = ref.getName();
	return *this;
}

std::string DiamondTrap::getName() const {
	std::cout << "DiamondTrap " << this->name << "'s getName called (return " << this->name << ")" << std::endl;
	return this->name;
}

void DiamondTrap::setName(std::string name) {
	std::cout << "DiamondTrap " << this->name << "'s setName called (set " << name << ")" << std::endl;
	this->name = name;
	ClapTrap::name = name + "_clap_name";
}

void DiamondTrap::toString() const {
	std::cout << "name: " << this->name << std::endl <<
				"ClapTrap name: " << ClapTrap::name << std::endl <<
				"hitPoints: " << this->hitPoints << std::endl <<
				"energyPoints: " << this->energyPoints << std::endl <<
				"attackDamage: " << this->attackDamage << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->name << std::endl <<
				"ClapTrap name: " << ClapTrap::name << std::endl;
}