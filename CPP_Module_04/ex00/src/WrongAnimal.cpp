/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:27:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:35:26 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal's defulat constructor is called." << std::endl;
	
	type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref) {
	std::cout << "WrongAnimal's copy constructor is called." << std::endl;
	
	*this = ref;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal's destructor is called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref) {
	if (this == &ref) {
		return *this;
	}
		
	setType(ref.getType());
	
	return *this;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

void WrongAnimal::makeSound() const {
	std::cout << "this is WrongAnimal class makeSound" << std::endl;
}