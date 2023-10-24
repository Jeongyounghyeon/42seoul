/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWorngCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:28:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/18 13:28:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat's defulat constructor is called." << std::endl;
	
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref) {
	std::cout << "WrongCat's copy constructor is called." << std::endl;
	
	*this = ref;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat's destructor is called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &ref) {
	if (this == &ref) {
		return *this;
	}
	
	WrongAnimal::operator=(ref);

	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow - meow -" << std::endl;
}