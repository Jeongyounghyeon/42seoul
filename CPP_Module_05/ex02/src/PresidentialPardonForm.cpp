/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:18:51 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/30 18:22:37 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : Form(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : Form(ref) {
	*this = ref;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) {
	if (this == &ref)
		return *this;

	return *this;
}

int PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!validBeforeExecute(executor)) {
		std::cout << executor.getName() << "'s grade is lower than PresidentialPardon's execute grade." << std::endl;
		return 1;
	}

	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return 0;
}
