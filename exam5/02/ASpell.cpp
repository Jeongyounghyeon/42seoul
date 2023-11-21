/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:01:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:47:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(const std::string name, const std::string effects) {
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(const ASpell &ref) {
	*this = ref;
}

ASpell::~ASpell() {
}

ASpell& ASpell::operator=(const ASpell& ref) {
	if (this == &ref)
		return *this;
	
	this->name = ref.getName();
	this->effects = ref.getEffects();

	return *this;
}

const std::string& ASpell::getName() const {
	return this->name;
}

const std::string& ASpell::getEffects() const {
	return this->effects;
}

void ASpell::launch(const ATarget& target) const {
	target.getHitBySpell(*this);
}
