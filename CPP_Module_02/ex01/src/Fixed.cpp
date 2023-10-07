/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:56:25 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/07 16:25:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : rawBits(num << this->fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : rawBits(roundf(num * (1 << this->fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref) {
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=(ref);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &ref)
		return *this;
	
	this->rawBits = ref.getRawBits();
	return *this;
}

int		Fixed::getRawBits(void) const {
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->getRawBits() / (1 << this->fractionalBits));
}

int		Fixed::toInt(void) const {
	return (this->getRawBits() >> this->fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed& ref) {
	out << ref.toFloat();
	return out;
}