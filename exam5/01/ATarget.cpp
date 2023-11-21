/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:06:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:46:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ATarget.hpp"

ATarget::ATarget(const std::string& type) {
	this->type = type;
}

ATarget::ATarget(const ATarget& ref) {
	*this = ref;
}


ATarget::~ATarget() {
}

ATarget& ATarget::operator=(const ATarget& ref) {
	if (this == &ref) {
		return *this;
	}

	this->type = ref.getType();
	
	return *this;
}

const std::string& ATarget::getType() const {
	return this->type;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
	std::cout << this->type << " has been " << spell.getEffects() << '!' << std::endl;
}
