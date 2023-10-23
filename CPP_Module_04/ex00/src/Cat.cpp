/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:06:06 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/18 13:22:03 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal() {
	setType("Cat");
}

Cat::Cat(const Cat& ref) : Animal(ref) {
	*this = ref;
	setType("Cat");
}

Cat::~Cat() {}

Cat& Cat::operator=(const Cat &ref) {
	if (this == &ref)
		return *this;
	Animal::operator=(ref);

	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow ~ meow ~" << std::endl;
}