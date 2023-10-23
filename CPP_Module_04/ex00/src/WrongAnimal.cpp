/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:27:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/18 13:28:06 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {}

WrongAnimal::WrongAnimal(const WrongAnimal& ref) {
	*this = ref;
}

WrongAnimal::~WrongAnimal() {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &ref) {
	if (this == &ref)
		return *this;
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