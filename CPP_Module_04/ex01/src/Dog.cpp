/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:11:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:36:21 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog's defualt constructor called." << std::endl;

	try {
		setBrain(new Brain());
	} catch (std::bad_alloc& eba) {
		std::cout << "Not enough memroy" << std::endl;
		std::exit(1);
	}
	setType("Dog");
}

Dog::Dog(const Dog& ref) : Animal(ref) {
	std::cout << "Dog's copy constructor called." << std::endl;
	
	try {
		setBrain(new Brain());
	} catch (std::bad_alloc& eba) {
		std::cout << "Not enough memroy" << std::endl;
		std::exit(1);
	}
	*this = ref;
}

Dog::~Dog() {
	std::cout << "Dog's destructor called." << std::endl;
	
	if (this->brain != 0) {
		delete this->brain;
	}
}

Dog& Dog::operator=(const Dog &ref) {
	if (this == &ref) {
		return *this;
	}
		
	Animal::operator=(ref);
	*(this->brain) = *ref.getBrain();

	return *this;
}

Brain*	Dog::getBrain() const {
	return this->brain;
}

void	Dog::setBrain(Brain *brain) {
	this->brain = brain;
}

void Dog::makeSound() const {
	std::cout << "Bow - wow" << std::endl;
}