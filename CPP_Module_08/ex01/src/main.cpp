/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:13:55 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/29 18:07:26 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "Span.hpp"

int subject();
int addNumbersSuccessTest();
int addNumbersFailTest();

int main() {
	subject();
	addNumbersSuccessTest();
	addNumbersFailTest();
}

int subject() {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}

int addNumbersSuccessTest() {
	Span sp = Span(5);
    std::vector<int> v(5, 0);

	try {
		sp.addNumbers(v);
	} catch (std::exception &e) {
		std::cout << "Fail add NumbersFailTest" << std::endl;
		return 1;
	}

	std::cout << "Success add NumbersFailTest" << std::endl;
	return 0;
}

int addNumbersFailTest() {
	Span sp = Span(5);
    std::vector<int> v(6, 0);

	try {
		sp.addNumbers(v);
	} catch (std::exception &e) {
		std::cout << "Success add NumbersFailTest" << std::endl;
		return 0;
	}

	std::cout << "Fail add NumbersFailTest" << std::endl;
	return 1;
}