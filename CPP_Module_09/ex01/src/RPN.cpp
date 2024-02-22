/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:11:02 by youjeong          #+#    #+#             */
/*   Updated: 2024/02/22 18:11:03 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>

RPN::~RPN() {}

void RPN::active(std::string expression) {
	try {
		validExpression(expression);
		calculate(expression);
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void RPN::calculate(std::string expression) {
	std::stack<int> st;

	for (size_t idx = 0; idx < expression.length(); idx++) {
		char c = expression[idx];

		if (idx % 2 == 1) {
			if (c != ' ') { throw std::runtime_error("Error"); }
		} else if (c >= '0' && c <= '9') {
			st.push(c - '0');
		} else {
			if (st.size() < 2) { throw std::runtime_error("Error: expression error"); }
		
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();

			if (c == '+') {
				st.push(a + b);
			} else if (c == '-') {
				st.push(a - b);
			} else if (c == '/') {
				if (b == 0) { throw std::runtime_error("Error: none"); }
				st.push(a / b);
			} else if (c == '*') {
				st.push(a * b);
			}
		}
	}

	if (st.size() != 1) { throw std::runtime_error("Error: expression error"); }
	
	std::cout << st.top() << std::endl;
}

void RPN::validExpression(std::string expression) {
	if (expression.length() % 2 == 0) { throw std::runtime_error("Error"); }

	for (size_t idx = 0; idx < expression.length(); idx++) {
		char c = expression[idx];

		if (idx % 2 != 0) {
			if (c != ' ') { throw std::runtime_error("Error"); }
		} else {
			if (!((c >= '0' && c <= '9')
				|| c == '+' || c == '-' || c == '/' || c == '*')
			) {
				throw std::runtime_error("Error");
			}
		}
	}
}