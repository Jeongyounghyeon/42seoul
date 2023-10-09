/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:00:08 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/09 15:38:15 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Fixed& x, const Fixed& y) : x(x.toFloat()), y(y.toFloat()) {}
Point::Point(const Point& ref) : x(ref.getX()), y(ref.getY()) {}
Point::~Point(void) {}

Point& Point::operator=(const Point& ref) {
	/*
	if (this == &ref)
		return *this;

	const_cast<Fixed&>(x) = ref.getX();
	const_cast<Fixed&>(y) = ref.getY();

	return *this;
	*/

	(void)ref;
	return *this;
}

Point Point::operator-(const Point& ref) {
	Point point(ref.getX() - this->x, ref.getY() - this->y);
	return point;
}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}

float Point::crossProduct(const Point& a, const Point& b) {
	return (a.getX() * b.getY() - a.getY() * b.getX()).toFloat();
}

std::ostream& operator<<(std::ostream &out, const Point& ref) {
	out << "x = " << ref.getX() << ", y = " << ref.getY();
	return out;
}
