/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:34:19 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/31 15:14:18 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name(""),
			signGrade(LOWEST_GRADE),
			executeGrade(LOWEST_GRADE) {
	this->sign = false;
}

Form::Form(const std::string& name, 
		const int& signGrade, 
		const int& executeGrade) : name(name),
								signGrade(signGrade),
								executeGrade(executeGrade) {
	if (signGrade < HIGHST_GRADE || executeGrade < HIGHST_GRADE)
		throw GradeTooHighException();
	if (signGrade > LOWEST_GRADE || executeGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	*this = Form();
}

Form::Form(const Form& ref) : name(ref.getName()),
							signGrade(ref.getSignGrade()),
							executeGrade(ref.getExecuteGrade()) {
	*this = Form();
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

const char* Form::GradeTooHighException::what(void) const throw() {
	return "grade is too high.";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "grade is too low.";
}
