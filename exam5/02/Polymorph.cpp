/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:29:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:53:49 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {
}

Polymorph::Polymorph(const Polymorph &ref) : ASpell(ref) {
	*this = ref;
}

Polymorph::~Polymorph() {
}

Polymorph& Polymorph::operator=(const Polymorph &ref) {
	if (this == &ref)
		return *this;
	
	ASpell::operator=(ref);

	return *this;
}

Polymorph* Polymorph::clone() const {
	return new Polymorph();
}