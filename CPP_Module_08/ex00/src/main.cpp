/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:24:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/12/29 17:11:49 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>

#include "easyfind.hpp"

void vectorTest();
void dequeTest();
void listTest();

int main() {
	vectorTest();
	dequeTest();
	listTest();
}

/**
 * vector test
 * vector 1, 2, 3을 push 후 2와 4를 순서대로 easyfind
*/
void vectorTest() {
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try {
		std::cout << *easyfind(v, 2) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(v, 4) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}

/**
 * deque
 * deque 1, 2, 3을 push 후 2와 4를 순서대로 easyfind
*/
void dequeTest() {
	std::deque<int> dq;

	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);

	try {
		std::cout << *easyfind(dq, 2) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(dq, 4) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}


/**
 * list
 * list 1, 2, 3을 push 후 2와 4를 순서대로 easyfind
*/
void listTest() {
	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try {
		std::cout << *easyfind(lst, 2) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << *easyfind(lst, 4) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}