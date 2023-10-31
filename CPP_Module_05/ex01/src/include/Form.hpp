/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:59:19 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/26 15:22:56 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		const int signGrade;
		const int executeGrade;
		bool sign;

		Form();

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};

	public:
		Form(const std::string& name, 
			const int& signGrade, 
			const int& executeGrade);
		Form(const Form& ref);
		~Form();

		Form& operator=(const Form& ref);

		std::string getName() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;
		bool		getSign() const;
		void		setSign(bool sign);

		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& ref);