/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:46:30 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/16 15:55:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test0();
void test1();
void test2();

int main() {
	test0();
	std::cout << std::endl;	
	test1();	
	std::cout << std::endl;	
	test2();	
	std::cout << std::endl;	

	return 0;
}

/* Feature Test */
void test0() {
	std::cout << "[ Feature Test ]" << std::endl;
	
	Form form("form", 100, 100);
	std::cout << form << std::endl;
}

/* Sign success Test */
void test1() {
	std::cout << "[ Sign Success Test]" << std::endl;
	
	Bureaucrat bureaucrat("test1", 1);
	Form form("form", 100, 100);
	
	bureaucrat.signForm(form);
	
	std::cout << "test1 complete!" << std::endl;
}

/* Sign fail Test */
void test2() {
	std::cout << "[ Sign Fail Test]" << std::endl;
	
	Bureaucrat bureaucrat("test1", 101);
	Form form("form", 100, 100);
	
	bureaucrat.signForm(form);
	
	std::cout << "test2 complete!" << std::endl;
}