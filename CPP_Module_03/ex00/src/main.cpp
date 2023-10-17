/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:32:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 18:46:20 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

void test1();
void test2();
void test3();
void test4();

int	main() {
	test1();
	std::cout << std::endl;
	test2();
	std::cout << std::endl;
	test3();
	std::cout << std::endl;
	test4();
}

/* 생성자 print Test */
void test1() {
	std::cout << "--------------------[Test1]--------------------" << std::endl;
	ClapTrap ct_test("test");
	ClapTrap ct_copy(ct_test);

	ct_test.toString();
	std::cout << std::endl;
	ct_copy.toString();
	std::cout << std::endl;
}

/* 함수 호출 및 기능 Test */
void test2() {
	std::cout << "--------------------[Test2]--------------------" << std::endl;
	ClapTrap ct_test("test");

	ct_test.toString();
	std::cout << std::endl;

	ct_test.attack("target1");
	ct_test.takeDamage(3);
	
	ct_test.toString();
	std::cout << std::endl;

	ct_test.beRepaired(4);

	ct_test.toString();
	std::cout << std::endl;
}

/* hitPoints 고갈 Test */
void test3() {
	std::cout << "--------------------[Test3]--------------------" << std::endl;
	ClapTrap ct_test("test");

	ct_test.toString();
	std::cout << std::endl;

	ct_test.takeDamage(20);
	ct_test.attack("target2");
	ct_test.takeDamage(1);
	ct_test.beRepaired(1);

	ct_test.toString();
	std::cout << std::endl;
}

/* energyPoints 고갈 Test */
void test4() {
	std::cout << "--------------------[Test4]--------------------" << std::endl;
	ClapTrap ct_test("test");

	ct_test.setEnergyPoints(2);

	ct_test.toString();
	std::cout << std::endl;

	ct_test.attack("target1");
	ct_test.attack("target2");
	ct_test.attack("target3");
	ct_test.takeDamage(1);
	ct_test.beRepaired(1);
	
	ct_test.toString();
	std::cout << std::endl;
}