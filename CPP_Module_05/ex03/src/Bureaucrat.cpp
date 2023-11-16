/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/16 16:16:41 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "grade is too low.";
}

Bureaucrat::Bureaucrat() : name("") {
	this->grade = LOWEST_GRADE;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : name(name) {
	*this = Bureaucrat();
	validGradeRange(grade);
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.getName()) {
	*this = Bureaucrat();
	*this = ref;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	if (this == &ref)
		return *this;

	setGrade(ref.getGrade());

	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::setGrade(int grade) {
	this->grade = grade;
}

void Bureaucrat::decrementGrade() {
	validGradeRange(grade - 1);
	setGrade(grade - 1);
}

void Bureaucrat::incrementGrade() {
	validGradeRange(grade + 1);
	setGrade(grade + 1);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref) {
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	
	return out;
}

void Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->name << " couldn’t sign " << form.getName() 
				<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const& form) const {
	if (form.execute(*this)) {
		std::cout << this->name << " executed " << form.getName() << std::cout;
	}
}

void Bureaucrat::validGradeRange(const int grade) const {
	if (grade < HIGHST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}
