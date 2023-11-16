/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:48:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/16 17:12:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <typeinfo>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {
}

Base::~Base() {
}

/**
 * Feature: A, B, C class를 random하게 인스턴스화
 * Return: random 인스턴스화된 객체
*/
Base* generate() {
	Base* pbase;

	try {
		switch (rand() % 3)
		{
		case 0:
			pbase = new A();
			break;
		case 1:
			pbase = new B();
			break;
		case 2:
			pbase = new C();
			break;
		default:
			pbase = 0;
		}
	} catch (const std::bad_alloc& e) {
		std::cerr << e.what() << std::endl;
	}

	return pbase;
}

/**
 * Feature: 실제 객체의 타입 출력
*/
void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "actually type: A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "actually type: B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "actually type: C" << std::endl;
}

/**
 * Feature: 실제 객체의 타입 출력
*/
void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "actually type: A" << std::endl;
	} catch (const std::bad_cast& e) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "actually type: B" << std::endl;
	} catch (const std::bad_cast& e) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "actually type: C" << std::endl;
	} catch (const std::bad_cast& e) {
	}
}