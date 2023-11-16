/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:30:52 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/16 16:14:38 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "grade is too low.";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	if (this == &ref)
		return *this;

	setGrade(ref.getGrade());

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref) {
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	
	return out;
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

void Bureaucrat::validGradeRange(const int grade) const {
	if (grade < HIGHST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}