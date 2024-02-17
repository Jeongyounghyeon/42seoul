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