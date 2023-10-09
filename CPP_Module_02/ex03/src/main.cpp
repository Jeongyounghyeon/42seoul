/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:37:12 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/09 15:40:31 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void) {
	Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point point(4, 2);

    bool inside = bsp(a, b, c, point);
    
    if (inside) {
        std::cout << "Point is inside the triangle." << std::endl;
    } else {
        std::cout << "Point is outside the triangle." << std::endl;
    }
}