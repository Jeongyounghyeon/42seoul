/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:59:41 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/09 15:40:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point a, Point b, Point c, Point point) {
	return ((Point::crossProduct(a - b, a - point) * Point::crossProduct(b - c, b - point) > 0) && 
			(Point::crossProduct(b - c, b - point) * Point::crossProduct(c - a, c - point) > 0));
}