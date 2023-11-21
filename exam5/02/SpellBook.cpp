/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:39:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 19:04:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SpellBook.hpp>

SpellBook::SpellBook() {
}

SpellBook::SpellBook(const SpellBook& ref) {
	*this = ref;
}

SpellBook::~SpellBook() {
}

SpellBook& SpellBook::operator=(const SpellBook& ref) {
	if (this == &ref)
		return *this;
	
	return *this;
}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell && (this->contents.find(spell->getName()) == this->contents.end())) {
		this->contents[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const &spellName) {
	if (this->contents.find(spellName) != this->contents.end()) {
		this->contents.erase(spellName);
	}
}

ASpell* SpellBook::createSpell(std::string const &spellName) {
	if (this->contents.find(spellName) != this->contents.end()) {
		return this->contents[spellName]->clone();
	}

	return 0;
}