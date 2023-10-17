/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:32:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 18:45:18 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"

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
	DiamondTrap dt_test("test");
	DiamondTrap dt_copy(dt_test);

	std::cout << std::endl;
	dt_test.toString();
	std::cout << std::endl;
	dt_copy.toString();
	std::cout << std::endl;
}

/* 함수 호출 및 기능 Test */
void test2() {
	std::cout << "--------------------[Test2]--------------------" << std::endl;
	DiamondTrap dt_test("test");

	dt_test.toString();
	std::cout << std::endl;

	dt_test.attack("target1");
	dt_test.takeDamage(3);
	
	dt_test.toString();
	std::cout << std::endl;

	dt_test.beRepaired(4);
	std::cout << std::endl;

	dt_test.guardGate();
	std::cout << std::endl;

	dt_test.highFivesGuys();
	std::cout << std::endl;

	dt_test.whoAmI();
	std::cout << std::endl;

	dt_test.toString();
	std::cout << std::endl;
}

/* hitpoints 고갈 Test */
void test3() {
	std::cout << "--------------------[Test3]--------------------" << std::endl;
	DiamondTrap dt_test("test");

	dt_test.toString();
	std::cout << std::endl;

	dt_test.takeDamage(100);
	dt_test.attack("target2");
	dt_test.takeDamage(1);
	dt_test.beRepaired(1);
	
	dt_test.toString();
	std::cout << std::endl;
}

/* energyPoints 고갈 Test */
void test4() {
	std::cout << "--------------------[Test4]--------------------" << std::endl;
	DiamondTrap dt_test("test");

	dt_test.setEnergyPoints(2);

	dt_test.toString();
	std::cout << std::endl;

	dt_test.attack("target1");
	dt_test.attack("target2");
	dt_test.attack("target3");
	dt_test.takeDamage(1);
	dt_test.beRepaired(1);
	
	dt_test.toString();
	std::cout << std::endl;
}