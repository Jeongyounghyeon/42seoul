/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:21:06 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:38:36 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& ref) : AMateria(ref) {
	*this = Cure();
	*this = ref;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& ref) {
	if (this == &ref) {
		return *this;
	}

	AMateria::operator=(ref);
	
	return *this;
}

AMateria* Cure::clone() const {
	Cure* cure;
	
	try {
		cure = new Cure(*this);
	} catch (std::bad_alloc& eba) {
		std::cout << "Not enough memroy" << std::endl;
		std::exit(1);
	}

	return cure;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}