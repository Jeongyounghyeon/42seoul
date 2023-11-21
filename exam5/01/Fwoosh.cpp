/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:29:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:53:49 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {
}

Fwoosh::Fwoosh(const Fwoosh &ref) : ASpell(ref) {
	*this = ref;
}

Fwoosh::~Fwoosh() {
}

Fwoosh& Fwoosh::operator=(const Fwoosh &ref) {
	if (this == &ref)
		return *this;
	
	ASpell::operator=(ref);

	return *this;
}

Fwoosh* Fwoosh::clone() const {
	return new Fwoosh();
}