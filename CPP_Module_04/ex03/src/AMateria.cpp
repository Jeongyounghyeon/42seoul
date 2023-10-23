/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:06:27 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/22 01:02:33 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &ref) {
	*this = ref;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& ref) {
	if (this == &ref)
		return *this;
	
	this->type = ref.getType();
	return *this;
}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* use materia to " << target.getName() << " *" << std::endl;
}