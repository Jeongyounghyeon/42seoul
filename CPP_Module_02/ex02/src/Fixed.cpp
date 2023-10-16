/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:40:30 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/16 17:22:41 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0) {}

Fixed::Fixed(const int num) : rawBits(num << this->fractionalBits) {}

Fixed::Fixed(const float num) : rawBits(roundf(num * (1 << this->fractionalBits))) {}

Fixed::Fixed(const Fixed& ref) {
	*this=(ref);
}

Fixed::~Fixed(void) {}

Fixed& Fixed::operator=(const Fixed& ref){
	if (this == &ref)
			return *this;

	this->rawBits = ref.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& ref) const {
	if (this->toFloat() > ref.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed& ref) const {
	if (this->toFloat() < ref.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed& ref) const {
	if (this->toFloat() >= ref.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed& ref) const {
	if (this->toFloat() <= ref.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed& ref) const {
	if (this->toFloat() == ref.toFloat())
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed& ref) const {
	if (this->toFloat() != ref.toFloat())
		return true;
	else
		return false;
}

Fixed Fixed::operator+(const Fixed& ref) const {
	Fixed fixed(this->toFloat() + ref.toFloat());
	return fixed;
}

Fixed Fixed::operator-(const Fixed& ref) const {
	Fixed fixed(this->toFloat() - ref.toFloat());
	return fixed;
}

Fixed Fixed::operator*(const Fixed& ref) const {
	Fixed fixed(this->toFloat() * ref.toFloat());
	return fixed;
}

Fixed Fixed::operator/(const Fixed& ref) const {
	Fixed fixed(this->toFloat() / ref.toFloat());
	return fixed;
}

Fixed& Fixed::operator++(void) {
	this->rawBits++;
	return *this;
}

const Fixed Fixed::operator++(int) {
	const Fixed fixed(*this);
	this->rawBits++;
	return fixed;
}

Fixed& Fixed::operator--(void) {
	this->rawBits--;
	return *this;
}

const Fixed Fixed::operator--(int) {
	const Fixed fixed(*this);
	this->rawBits--;
	return fixed;
}

Fixed& Fixed::min(Fixed& ref1, Fixed& ref2) {
	if (ref1 < ref2)
		return ref1;
	else
		return ref2;
}

const Fixed& Fixed::min(const Fixed& ref1, const Fixed& ref2) {
	if (ref1 < ref2)
		return ref1;
	else
		return ref2;
}

Fixed& Fixed::max(Fixed& ref1, Fixed& ref2) {
	if (ref1 > ref2)
		return ref1;
	else
		return ref2;
}

const Fixed& Fixed::max(const Fixed& ref1, const Fixed& ref2) {
	if (ref1 > ref2)
		return ref1;
	else
		return ref2;
}

int	Fixed::getRawBits(void) const {
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->rawBits / (1 << this->fractionalBits));
}

int	Fixed::toInt(void) const {
	return (this->rawBits >> this->fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed& ref) {
	out << ref.toFloat();
	return out;
}
