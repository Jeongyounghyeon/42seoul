/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:06:06 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:35:07 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat's defulat constructor is called." << std::endl;
	
	setType("Cat");
}

Cat::Cat(const Cat& ref) : Animal(ref) {
	std::cout << "Cat's copy constructor is called." << std::endl;
	
	*this = ref;
}

Cat::~Cat() {
	std::cout << "Cat's destructor is called." << std::endl;
}

Cat& Cat::operator=(const Cat &ref) {
	if (this == &ref) {
		return *this;
	}

	Animal::operator=(ref);

	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow ~ meow ~" << std::endl;
}