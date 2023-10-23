/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:06:06 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/23 16:36:08 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat's defualt constructor called." << std::endl;
	setType("Cat");
	try {
		setBrain(new Brain());
	} catch (std::bad_alloc& eba) {
		std::cout << "Not enough memroy" << std::endl;
		std::exit(1);
	}
}

Cat::Cat(const Cat& ref) : Animal(ref) {
	std::cout << "Cat's copy constructor called." << std::endl;
	setType("Cat");
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
	if (this->brain != NULL)
		delete this->brain;
}

Cat& Cat::operator=(const Cat &ref) {
	if (this == &ref)
		return *this;
	Animal::operator=(ref);
	*(this->brain) = *ref.brain;

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