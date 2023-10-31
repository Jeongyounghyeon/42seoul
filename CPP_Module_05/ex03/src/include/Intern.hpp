/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:18:29 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/31 16:17:47 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "AForm.hpp"

class Intern {
	private:
		static const std::string types[3];
		static Form* (Intern::*forms[3])(const std::string&) const;

		class FormNotFoundException: public std::exception {
			const char*	what() const throw();
		};

		Form* getNewShrubberyCreationForm(const std::string& name) const;
		Form* getRobotomyRequestForm(const std::string& name) const ;
		Form* getPresidentialPardonForm(const std::string& name) const;

	public:
		Intern();
		Intern(const Intern& ref);
		~Intern();

		Intern& operator=(const Intern& ref);

		Form* makeForm(const std::string type, const std::string name);
};