/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:10:32 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:38:43 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& ref) : AMateria(ref) {
	*this = Ice();
	*this = ref;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& ref) {
	if (this == &ref) {
		return *this;
	}

	AMateria::operator=(ref);
	
	return *this;
}

AMateria* Ice::clone() const {
	Ice* ice;
	
	try {
		ice = new Ice(*this);
	} catch (std::bad_alloc& eba) {
		std::cout << "Not enough memroy" << std::endl;
		std::exit(1);
	}

	return ice;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}