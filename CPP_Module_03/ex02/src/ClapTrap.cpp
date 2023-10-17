/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:07:42 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 19:20:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), 
						hitPoints(10), 
						energyPoints(10), 
						attackDamage(0) {
	std::cout << "ClapTrap's default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), 
										hitPoints(10), 
										energyPoints(10), 
										attackDamage(0) {
	std::cout << "ClapTrap " << this->name << "'s constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref) {
	std::cout << "ClapTrap's copy constructor called" << std::endl;
	*this = ref;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap's destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref) {
	std::cout << "ClapTrap's operator = called" << std::endl;
	if (this == &ref)
		return *this;

	this->name = ref.getName();
	this->hitPoints = ref.getHitPoints();
	this->energyPoints = ref.getEnergyPoints();
	this->attackDamage = ref.getAttackDamage();
	return *this;
}

std::string ClapTrap::getName() const {
	std::cout << "ClapTrap " << this->name << "'s getName called (return " << this->name << ")" << std::endl;
	return this->name;
}

int ClapTrap::getHitPoints() const {
	std::cout << "ClapTrap " << this->name << "'s getHitPoints called (return " << this->hitPoints << ")" << std::endl;
	return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	std::cout << "ClapTrap " << this->name << "'s getEnergyPoints called (return " << this->energyPoints << ")" << std::endl;
	return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	std::cout << "ClapTrap " << this->name << "'s getAttackDamage called (return " << this->attackDamage << ")" << std::endl;
	return this->attackDamage;
}

void ClapTrap::setName(std::string name) {
	std::cout << "ClapTrap " << this->name << "'s setName called (set " << name << ")" << std::endl;
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
	std::cout << "ClapTrap " << this->name << "'s setHitPoints called (set " << hitPoints << ")" << std::endl;
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	std::cout << "ClapTrap " << this->name << "'s setEnergyPoints called (set " << energyPoints << ")" << std::endl;
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	std::cout << "ClapTrap " << this->name << "'s setAttackDamage called (set " << attackDamage << ")" << std::endl;
	this->attackDamage = attackDamage;
}

void ClapTrap::toString() const {
	std::cout << "name: " << this->name << std::endl <<
				"hitPoints: " << this->hitPoints << std::endl <<
				"energyPoints: " << this->energyPoints << std::endl <<
				"attackDamage: " << this->attackDamage << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!this->hitPoints || !this->energyPoints)
		std::cout << "ClapTrap " << this->name << " failed to attack " << target << "! (attack)" << std::endl;
	else {
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->hitPoints)
		std::cout << "ClapTrap " << this->name << " is already dead! (takeDamage)" << std::endl;
	else if (!this->energyPoints)
		std::cout << "ClapTrap " << this->name << " has no enery! (takeDamge)" << std::endl;
	else {
		std::cout << "ClapTrap " << this->name << " is taken " << amount << " damage!" << std::endl;
		if (this->hitPoints < amount)
			this->hitPoints = 0;
		else
			this->hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->hitPoints)
		std::cout << "ClapTrap " << this->name << " is already dead! (beRepaired)" << std::endl;
	else if (!this->energyPoints)
		std::cout << "ClapTrap " << this->name << " has no enery! (beRepaired)" << std::endl;
	else {
		std::cout << "ClapTrap " << this->name << " repaired " << amount << " points self!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
}