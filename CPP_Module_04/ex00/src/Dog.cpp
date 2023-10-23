/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/18 13:22:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal() {
	setType("Dog");
}

Dog::Dog(const Dog& ref) : Animal(ref) {
	*this = ref;
	setType("Dog");
}

Dog::~Dog() {}

Dog& Dog::operator=(const Dog &ref) {
	if (this == &ref)
		return *this;
	Animal::operator=(ref);

	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bow - wow" << std::endl;
}