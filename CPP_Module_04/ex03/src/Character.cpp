/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:20:01 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/23 15:19:57 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Character.hpp"

Character::Character() : name("") {
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		this->inventory[idx] = 0;
}

Character::Character(const std::string& name) : name(name) {
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		this->inventory[idx] = 0;
}

Character::Character(const Character& ref) {
	*this = Character();
	*this = ref;
}

Character::~Character() {
	for (int idx = 0; idx < INVENTORY_SIZE; idx++)
		unequip(idx);
}

Character& Character::operator=(const Character& ref) {
	if (this == &ref)
		return *this;

	this->name = ref.getName();
	for (int idx = 0; idx < INVENTORY_SIZE; idx++) {
		unequip(idx);
		this->inventory[idx] = ref.inventory[idx]->clone();
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
	if (this->inventory[idx] != 0)
		delete this->inventory[idx];
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
	this->inventory[idx]->use(target);
}