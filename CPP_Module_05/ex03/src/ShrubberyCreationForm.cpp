/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:28:23 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/30 18:22:37 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : Form(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : Form(ref) {
	*this = ref;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
	if (this == &ref)
		return *this;

	return *this;
}

int ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	std::ofstream ofs;
	std::string filename = executor.getName() + "_shrubbery";
	
	if (!validBeforeExecute(executor)) {
		std::cout << executor.getName() << "'s grade is lower than ShrubberyCreation's execute grade." << std::endl;
		return 1;
	}

	ofs.open(filename.c_str());
	if (ofs.fail()) {
		std::cout << "fail to open " << filename << " file." << std::endl;
		return 1;
	}

	ofs << ASCII_TREE;

	return 0;
}