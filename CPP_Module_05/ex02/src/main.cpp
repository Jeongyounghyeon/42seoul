/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:12:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/30 18:46:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void shrubberyCreationFormTest();
void robotomyRequestFormTest();
void presidentialPardonFormTest();
void shrubberyCreationFormSignFailTest();
void robotomyRequestFormSignFailTest();
void presidentialPardonFormSignFailTest();
void shrubberyCreationFormExecuteFailTest();
void robotomyRequestFormExecuteFailTest();
void presidentialPardonFormExecuteFailTest();

int main() {
	shrubberyCreationFormTest();
	robotomyRequestFormTest();
	presidentialPardonFormTest();
	shrubberyCreationFormSignFailTest();
	robotomyRequestFormSignFailTest();
	presidentialPardonFormSignFailTest();
	shrubberyCreationFormExecuteFailTest();
	robotomyRequestFormExecuteFailTest();
	presidentialPardonFormExecuteFailTest();

	return 0;
}

void shrubberyCreationFormTest() {
	Bureaucrat bureaucrat("shrubbery executor", 1);
	ShrubberyCreationForm shrubberyForm("shrubbery form");

	try {
		shrubberyForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of shrubberyCreationFormTest" << std::endl;
	}
	shrubberyForm.execute(bureaucrat);
}

void robotomyRequestFormTest() {
	Bureaucrat bureaucrat("robotomy executor", 1);
	RobotomyRequestForm robotomyRequestForm("robotomy form");

	try {
		robotomyRequestForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of robotomyRequestFormTest" << std::endl;
	}
	robotomyRequestForm.execute(bureaucrat);
}

void presidentialPardonFormTest() {
	Bureaucrat bureaucrat("presidential executor", 1);
	PresidentialPardonForm presidentialPardonForm("presidential form");

	try {
		presidentialPardonForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of presidentialPardonFormTest" << std::endl;
	}
	presidentialPardonForm.execute(bureaucrat);
}

void shrubberyCreationFormSignFailTest() {
	Bureaucrat bureaucrat("shrubbery executor", 146);
	ShrubberyCreationForm shrubberyForm("shrubbery form");

	try {
		shrubberyForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of shrubberyCreationFormSignFailTest" << std::endl;
	}
	shrubberyForm.execute(bureaucrat);
}

void robotomyRequestFormSignFailTest() {
	Bureaucrat bureaucrat("robotomy executor", 73);
	RobotomyRequestForm robotomyRequestForm("robotomy form");

	try {
		robotomyRequestForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of robotomyRequestFormSignFailTest" << std::endl;
	}
	robotomyRequestForm.execute(bureaucrat);
}

void presidentialPardonFormSignFailTest() {
	Bureaucrat bureaucrat("presidential executor", 26);
	PresidentialPardonForm presidentialPardonForm("presidential form");

	try {
		presidentialPardonForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of presidentialPardonFormSignFailTest" << std::endl;
	}
	presidentialPardonForm.execute(bureaucrat);
}


void shrubberyCreationFormExecuteFailTest() {
	Bureaucrat bureaucrat("shrubbery executor", 145);
	ShrubberyCreationForm shrubberyForm("shrubbery form");

	try {
		shrubberyForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of shrubberyCreationFormExecuteFailTest" << std::endl;
	}
	shrubberyForm.execute(bureaucrat);
}

void robotomyRequestFormExecuteFailTest() {
	Bureaucrat bureaucrat("robotomy executor", 72);
	RobotomyRequestForm robotomyRequestForm("robotomy form");

	try {
		robotomyRequestForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of robotomyRequestFormExecuteFailTest" << std::endl;
	}
	robotomyRequestForm.execute(bureaucrat);
}

void presidentialPardonFormExecuteFailTest() {
	Bureaucrat bureaucrat("presidential executor", 25);
	PresidentialPardonForm presidentialPardonForm("presidential form");

	try {
		presidentialPardonForm.beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of presidentialPardonFormExecuteFailTest" << std::endl;
	}
	presidentialPardonForm.execute(bureaucrat);
}