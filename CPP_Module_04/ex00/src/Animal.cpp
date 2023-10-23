/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:13:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/18 13:28:11 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Animal.hpp"

Animal::Animal() : type("") {}

Animal::Animal(const Animal& ref) {
	*this = ref;
}

Animal::~Animal() {}

Animal& Animal::operator=(const Animal &ref) {
	if (this == &ref)
		return *this;
	setType(ref.getType());
	
	return *this;
}

std::string	Animal::getType() const {
	return this->type;
}

void Animal::setType(std::string type) {
	this->type = type;
}

void Animal::makeSound() const {
	std::cout << "this is Animal class makeSound" << std::endl;
}