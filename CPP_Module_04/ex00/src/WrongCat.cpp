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
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref) {
	*this = ref;
	setType("WrongCat");
}

WrongCat::~WrongCat() {}

WrongCat& WrongCat::operator=(const WrongCat &ref) {
	if (this == &ref)
		return *this;
	WrongAnimal::operator=(ref);

	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow - meow -" << std::endl;
}