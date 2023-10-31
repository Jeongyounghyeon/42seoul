/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:12:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/31 16:24:44 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void shrubberyCreationFormTest();
void robotomyRequestFormTest();
void presidentialPardonFormTest();
void noDefinedFormTest();

int main() {
	shrubberyCreationFormTest();
	robotomyRequestFormTest();
	presidentialPardonFormTest();
	noDefinedFormTest();

	return 0;
}

void shrubberyCreationFormTest() {
	Bureaucrat bureaucrat("shrubbery executor", 1);
	Intern intern;
	Form *form;

	form = intern.makeForm("shrubbery creation", "shrubbery form");
	if (form == 0)
		return;

	try {
		form->beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of shrubberyCreationFormTest" << std::endl;
	}
	form->execute(bureaucrat);

	delete form;
}

void robotomyRequestFormTest() {
	Bureaucrat bureaucrat("robotomy executor", 1);
	Intern intern;
	Form *form;

	form = intern.makeForm("robotomy request", "robotomy form");
	if (form == 0)
		return;
	
	try {
		form->beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of robotomyRequestFormTest" << std::endl;
	}
	form->execute(bureaucrat);
	
	delete form;
}

void presidentialPardonFormTest() {
	Bureaucrat bureaucrat("presidential executor", 1);
	Intern intern;
	Form *form;

	form = intern.makeForm("presidential pardon", "presidential form");
	if (form == 0)
		return;
	
	try {
		form->beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of presidentialPardonFormTest" << std::endl;
	}
	form->execute(bureaucrat);

	delete form;
}

void noDefinedFormTest() {
	Bureaucrat bureaucrat("presidential executor", 1);
	Intern intern;
	Form *form = 0;

	try {
		form = intern.makeForm("no form", "presidential form");
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	if (form == 0)
		return;
	
	try {
		form->beSigned(bureaucrat);
	} catch (std::exception& e) {
		std::cout << "catch exception of presidentialPardonFormTest" << std::endl;
	}
	form->execute(bureaucrat);

	delete form;
}