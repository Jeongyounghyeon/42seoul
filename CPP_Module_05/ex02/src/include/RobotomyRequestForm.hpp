/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:54:07 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/30 18:23:46 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public Form {
	private:
		RobotomyRequestForm();
	
	public:
		RobotomyRequestForm(const std::string& name);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);

		int execute(Bureaucrat const& executor) const;
};