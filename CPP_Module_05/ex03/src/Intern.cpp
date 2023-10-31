/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:26:42 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/31 16:24:39 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string Intern::types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
Form* (Intern::*Intern::forms[3])(const std::string&) const = {
    &Intern::getNewShrubberyCreationForm,
    &Intern::getRobotomyRequestForm,
    &Intern::getPresidentialPardonForm
};

Intern::Intern() {}

Intern::Intern(const Intern& ref) {
	*this = ref;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& ref) {
	if (this == &ref)
		return *this;
	
	return *this;
}

Form* Intern::getNewShrubberyCreationForm(const std::string& name) const {
	return new ShrubberyCreationForm(name);
}

Form* Intern::getRobotomyRequestForm(const std::string& name) const {
	return new RobotomyRequestForm(name);
}

Form* Intern::getPresidentialPardonForm(const std::string& name) const {
	return new PresidentialPardonForm(name);
}

Form* Intern::makeForm(const std::string type, const std::string name) {
	int index;

	for (index = 0; index < 3; index++) {
		if (types[index] == type) {
			break;
		}
	}

	if (index < 3) {
		return (this->*forms[index])(name);
	} else {
		throw FormNotFoundException();
	}
	return 0;
}

const char*	Intern::FormNotFoundException::what() const throw() {
	return "form type is not exist.";
}