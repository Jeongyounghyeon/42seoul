/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:55:41 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/16 16:20:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : Form(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : Form(ref) {
	*this = ref;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) {
	if (this == &ref)
		return *this;

	return *this;
}

int RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!validBeforeExecute(executor)) {
		std::cout << executor.getName() << "'s grade is lower than RobotomyRequest's execute grade." << std::endl;
		return 1;
	}

	std::cout << "rizzz~ rizzz~" << std::endl;
	std::srand(time(0));
	if (std::rand() % 2) {
		std::cout << executor.getName() << " is successfully robotomized." << std::endl;
	} else {
		std::cout << executor.getName() << " is failed to robotomized." << std::endl;
	}

	return 0;
}