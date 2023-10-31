/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:27:37 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/31 15:03:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

#define HIGHST_GRADE 1
#define LOWEST_GRADE 150

class Form;

class Bureaucrat {
	private:
		const std::string name;
		int grade;

		Bureaucrat();

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};

	public:
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat& ref);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& ref);

		std::string getName() const;
		int			getGrade() const;
		void		setGrade(int grade);

		void decrementGrade();
		void incrementGrade();

		void signForm(Form &form) const;
		void executeForm(Form const& form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref);