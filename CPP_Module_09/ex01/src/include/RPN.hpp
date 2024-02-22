/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:10:59 by youjeong          #+#    #+#             */
/*   Updated: 2024/02/22 18:11:00 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>

#pragma once

class RPN {
	private:
		RPN();
		RPN(const RPN& ref);

		RPN& operator=(const RPN& ref);
		
		static void calculate(std::string expression);
		static void validExpression(std::string expression);
	public:
		virtual ~RPN();

		static void active(std::string expression);
};