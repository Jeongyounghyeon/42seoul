/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:19 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/31 16:19:58 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form(const std::string& name, 
		const int& signGrade, 
		const int& executeGrade) : name(name),
								signGrade(signGrade),
								executeGrade(executeGrade) {
	if (signGrade < HIGHST_GRADE || executeGrade < HIGHST_GRADE)
		throw GradeTooHighException();
	if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	this->initIv();
}


Form::Form(const Form& ref) : name(ref.getName()),
							signGrade(ref.getSignGrade()),
							executeGrade(ref.getExecuteGrade()) {
	this->initIv();
}

Form::~Form() {}

Form& Form::operator=(const Form& ref) {
	if (this == &ref)
		return *this;
	
	this->sign = ref.getSign();
	
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& ref) {
	out << "name: " << ref.getName() << std::endl
		<< "signGrade: " << ref.getSignGrade() << std::endl
		<< "executeGrade: " << ref.getExecuteGrade() << std::endl
		<< "sign: " << std::boolalpha << ref.getSign() << std::noboolalpha;
	return out;
}

void Form::initIv() {
	this->sign = false;
}

std::string Form::getName() const {
	return this->name;
}

int Form::getSignGrade() const {
	return this->signGrade;
}

int Form::getExecuteGrade() const {
	return this->executeGrade;
}

bool Form::getSign() const {
	return this->sign;
}

void Form::setSign(bool sign) {
	this->sign = sign;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	
	this->sign = true;
}

bool Form::validFormSignGrade(const Bureaucrat& bureaucrat) const {
	if (bureaucrat.getGrade() > this->signGrade)
		return false;

	return true;
}

bool Form::validFormExecuteGrade(const Bureaucrat& bureaucrat) const {
	if (bureaucrat.getGrade() > this->executeGrade)
		return false;

	return true;
}

bool Form::validBeforeExecute(const Bureaucrat& bureaucrat) const {
	if (this->sign != true
		|| !validFormExecuteGrade(bureaucrat))
		return false;
	
	return true;
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return "grade is too high.";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "grade is too low.";
}