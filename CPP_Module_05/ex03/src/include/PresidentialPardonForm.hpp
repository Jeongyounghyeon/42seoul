/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:18:16 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/30 18:23:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public Form {
	private:
		PresidentialPardonForm();
	
	public:
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);

		int execute(Bureaucrat const& executor) const;
};