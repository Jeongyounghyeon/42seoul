/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:19:35 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 18:52:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : name(name) {
	this->title = title;

	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const {
	return this->name;
}

const std::string& Warlock::getTitle() const {
	return this->title;
}

void Warlock::setTitle(const std::string& title) {
	this->title = title;
}

void Warlock::introduce() const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << '!' << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
	// if (spell && (this->spellBook.find(spell->getName()) == this->spellBook.end())) {
	// 	spellBook[spell->getName()] = spell->clone();
	// }
	this->spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string& spellName) {
	// if (this->spellBook.find(spellName) != this->spellBook.end()) {
	// 	this->spellBook.erase(spellName);
	// }
	this->spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string& spellName, const ATarget& target) {
	ASpell *spell = this->spellBook.createSpell(spellName);
	
	if (spell != 0) {
		target.getHitBySpell(*spell);
	}
}