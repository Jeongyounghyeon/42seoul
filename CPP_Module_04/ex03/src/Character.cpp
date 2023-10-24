/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:20:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:38:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Character.hpp"

Character::Character() {
	for (int idx = 0; idx < INVENTORY_SIZE; idx++) {
		this->inventory[idx] = 0;
	}
	name = "";
}

Character::Character(const std::string& name) {
	for (int idx = 0; idx < INVENTORY_SIZE; idx++) {
		this->inventory[idx] = 0;
	}
	this->name = name;
}

Character::Character(const Character& ref) {
	*this = Character();
	*this = ref;
}

Character::~Character() {
	for (int idx = 0; idx < INVENTORY_SIZE; idx++) {
		if (this->inventory[idx] != 0) {
			delete this->inventory[idx];
		}
	}
}

Character& Character::operator=(const Character& ref) {
	if (this == &ref) {
		return *this;
	}

	this->name = ref.getName();
	for (int idx = 0; idx < INVENTORY_SIZE; idx++) {
		if (this->inventory[idx] != 0) {
			delete this->inventory[idx];
		}
		if (ref.inventory[idx] != 0) {
			this->inventory[idx] = ref.inventory[idx]->clone();
		}
	}
	
	return *this;
}

std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	int idx = 0;

	while (idx < INVENTORY_SIZE) {
		if (this->inventory[idx] == 0) {
			this->inventory[idx] = m;
			return;
		}
		idx++;
	}
}

void Character::unequip(int idx) {
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
	this->inventory[idx]->use(target);
}