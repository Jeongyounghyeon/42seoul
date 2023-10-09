/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:47:08 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/09 17:51:27 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Fixed& x, const Fixed& y);
	Point(const Point& ref);
	~Point(void);

	Point& operator=(const Point& ref);
	Point operator-(const Point& ref);
	
	Fixed getX() const;
	Fixed getY() const;

    static float crossProduct(const Point& a, const Point& b);
};

std::ostream& operator<<(std::ostream &out, const Point& ref);
bool bsp( Point a, Point b, Point c, Point point);