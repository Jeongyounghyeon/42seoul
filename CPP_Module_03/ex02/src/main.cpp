/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:32:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 18:45:32 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "FragTrap.hpp"

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
	FragTrap ft_test("test");
	FragTrap ft_copy(ft_test);

	std::cout << std::endl;
	ft_test.toString();
	std::cout << std::endl;
	ft_copy.toString();
	std::cout << std::endl;
}

/* 함수 호출 및 기능 Test */
void test2() {
	std::cout << "--------------------[Test2]--------------------" << std::endl;
	FragTrap ft_test("test");

	ft_test.toString();
	std::cout << std::endl;

	ft_test.attack("target1");
	ft_test.takeDamage(3);
	
	ft_test.toString();
	std::cout << std::endl;

	ft_test.beRepaired(4);
	std::cout << std::endl;

	ft_test.highFivesGuys();
	std::cout << std::endl;

	ft_test.toString();
	std::cout << std::endl;
}

/* hitpoints 고갈 Test */
void test3() {
	std::cout << "--------------------[Test3]--------------------" << std::endl;
	FragTrap ft_test("test");

	ft_test.toString();
	std::cout << std::endl;

	ft_test.takeDamage(100);
	ft_test.attack("target2");
	ft_test.takeDamage(1);
	ft_test.beRepaired(1);
	
	ft_test.toString();
	std::cout << std::endl;
}

/* energyPoints 고갈 Test */
void test4() {
	std::cout << "--------------------[Test4]--------------------" << std::endl;
	FragTrap ft_test("test");

	ft_test.setEnergyPoints(2);

	ft_test.toString();
	std::cout << std::endl;

	ft_test.attack("target1");
	ft_test.attack("target2");
	ft_test.attack("target3");
	ft_test.takeDamage(1);
	ft_test.beRepaired(1);
	
	ft_test.toString();
	std::cout << std::endl;
}