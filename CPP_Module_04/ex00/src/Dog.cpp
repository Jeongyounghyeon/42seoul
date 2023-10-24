/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:35:14 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog's defulat constructor is called." << std::endl;
	
	setType("Dog");
}

Dog::Dog(const Dog& ref) : Animal(ref) {
	std::cout << "Dog's copy constructor is called." << std::endl;
	
	*this = ref;
}

Dog::~Dog() {
	std::cout << "Dog's destructor is called." << std::endl;
}

Dog& Dog::operator=(const Dog &ref) {
	if (this == &ref) {
		return *this;
	}

	Animal::operator=(ref);

	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bow - wow" << std::endl;
}