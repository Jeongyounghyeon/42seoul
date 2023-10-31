/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:46:30 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/31 15:03:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main() {
	test0();
	std::cout << std::endl;	
	test1();	
	std::cout << std::endl;	
	test2();	
	std::cout << std::endl;	
	test3();	
	std::cout << std::endl;	
	test4();	
	std::cout << std::endl;	
	test5();	
	std::cout << std::endl;	
	test6();	

	return 0;
}

/* No catch Test */
void test0() {
	std::cout << "[No catch Test]" << std::endl;
	try
	{
		Bureaucrat bureaucrat1("test0", 1);
		Bureaucrat bureaucrat2("test0", 150);
		std::cout << "test0 complete!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test0 fail!" << std::endl;
	}
}

/* Higher grade Test */
void test1() {
	std::cout << "[Higher grade Test]" << std::endl;
	try
	{
		Bureaucrat bureaucrat("test1", 0);
		std::cout << "test1 fail!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test1 complete!" << std::endl;
	}
}

/* Lower grade Test */
void test2() {
	std::cout << "[Lower grade Test]" << std::endl;
	try
	{
		Bureaucrat bureaucrat("test2", 151);
		std::cout << "test2 fail!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test2 complete!" << std::endl;
	}
}

/* Success decrementGrade Test */
void test3() {
	std::cout << "[Success decrementGrade Test]" << std::endl;
	try
	{
		Bureaucrat bureaucrat("test3", 2);
		bureaucrat.decrementGrade();
		std::cout << "test3 complete!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test3 fail!" << std::endl;
	}
}

/* Fail decrementGrade Test */
void test4() {
	std::cout << "[Fail decrementGrade Test]" << std::endl;
	try
	{
		Bureaucrat bureaucrat("test4", 1);
		bureaucrat.decrementGrade();
		std::cout << "test4 fail!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test4 complete!" << std::endl;
	}
}

/* Success incrementGrade Test */
void test5() {
	std::cout << "[Success incrementGrade Test]" << std::endl;
	try
	{
		Bureaucrat bureaucrat("test5", 149);
		bureaucrat.incrementGrade();
		std::cout << "test5 complete!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test5 fail!" << std::endl;
	}
}

/* fail incrementGrade Test */
void test6() {
	std::cout << "[Success incrementGrade Test]" << std::endl;
	try
	{
		Bureaucrat bureaucrat("test6", 150);
		bureaucrat.incrementGrade();
		std::cout << "test6 fail!" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "test6 complete!" << std::endl;
	}
}