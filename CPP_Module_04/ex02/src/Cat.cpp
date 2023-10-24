/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:06:06 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:37:29 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat's defualt constructor called." << std::endl;
	
	try {
		setBrain(new Brain());
	} catch (std::bad_alloc& eba) {
		std::cout << "Not enough memroy" << std::endl;
		std::exit(1);
	}
	setType("Cat");
}

Cat::Cat(const Cat& ref) : Animal(ref) {
	std::cout << "Cat's copy constructor called." << std::endl;
	
	try {
		setBrain(new Brain());
	} catch (std::bad_alloc& eba) {
		std::cout << "Not enough memroy" << std::endl;
		std::exit(1);
	}
	*this = ref;
}

Cat::~Cat() {
	std::cout << "Cat's destructor called." << std::endl;
	
	if (this->brain != 0) {
		delete this->brain;
	}
}

Cat& Cat::operator=(const Cat &ref) {
	if (this == &ref) {
		return *this;
	}
	
	Animal::operator=(ref);
	*(this->brain) = *ref.getBrain();

	return *this;
}

Brain*	Cat::getBrain() const {
	return this->brain;
}

void	Cat::setBrain(Brain *brain) {
	this->brain = brain;
}

void Cat::makeSound() const {
	std::cout << "Meow ~ meow ~" << std::endl;
}