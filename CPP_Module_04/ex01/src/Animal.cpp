/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:13:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/18 13:47:53 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Aniaml's defualt constructor called." << std::endl;
}

Animal::Animal(const Animal& ref) {
	std::cout << "Animal's copy constructor called." << std::endl;
	*this = ref;
}

Animal::~Animal() {
	std::cout << "Animal's destructor called." << std::endl;
}

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

