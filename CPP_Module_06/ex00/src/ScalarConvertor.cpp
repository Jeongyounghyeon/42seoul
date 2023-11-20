/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:57:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 16:55:07 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

#include "ScalarConvertor.hpp"

void ScalarConvertor::convert(const std::string& str)
{
	if (isChar(str)) {
		return convert(str[0]);
	}
	if (isInt(str)) {
		return convert(strtol(str.c_str(), NULL, 10));
	}
	if (isFloat(str)) {
		return convert(strtof(str.c_str(), NULL));
	}
	if (isDouble(str)) {
		return convert(strtod(str.c_str(), NULL));
	} 
	convertImpossible();
}

template <typename T>
void ScalarConvertor::convert(const T& value) {
	try {
		char valueOfChar = toChar(value);

		std::cout << "char: " << '\'' << valueOfChar << '\'' << std::endl; 
	} catch (std::string& msg) {
		std::cerr << "char: " << msg << std::endl;
	}

	try {
		int valueOfInt = toInt(value);

		std::cout << "int: " << valueOfInt << std::endl; 
	} catch (std::string& msg) {
		std::cerr << "int: " << msg << std::endl;
	}
	
	try {
		float valueOfFloat = toFloat(value);
		
		if (valueOfFloat == static_cast<long long>(value)) {
			std::cout << "float: " << valueOfFloat << ".0f" << std::endl; 
		} else {
			std::cout << "float: " << valueOfFloat << "f" << std::endl; 
		}
	} catch (std::string& msg) {
		std::cerr << "float: " << msg << std::endl;
	}

	try {
		double valueOfDouble = toDouble(value);
		
		if (valueOfDouble == static_cast<long long>(value)) {
			std::cout << "double: " << valueOfDouble << ".0" << std::endl; 
		} else {
			std::cout << "double: " << valueOfDouble << std::endl; 
		}
	} catch (std::string& msg) {
		std::cerr << "double: " << msg << std::endl;
	}
}

void ScalarConvertor::convertImpossible() {
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible" << std::endl;
	std::cout << "double: " << "impossible" << std::endl;
}

template <typename T>
char ScalarConvertor::toChar(const T& value) {
	if (std::isnan(value) || static_cast<long long>(value) != value) {
		throw std::string("impossible");
	}
	if ((value < 0) || (value > 255)) {
		throw std::string("overflow");
	}
	if ((value < 32) || (value > 126)) {
		throw std::string("can't display");
	}

	return static_cast<char>(value);
}

char ScalarConvertor::toChar(const int& value) {
	if ((value < 0) || (value > 255)) {
		throw std::string("overflow");
	}
	if ((value < 32) || (value > 126)) {
		throw std::string("can't display");
	}

	return static_cast<char>(value);
}

template <typename T>
int ScalarConvertor::toInt(const T& value) {
	if (value != static_cast<long long>(value)) {
		throw std::string("impossible");
	}
	if (value < static_cast<T> (INT_MIN) || value > static_cast<T> (INT_MAX)) {
		throw std::string("overflow");
	}
	
	return static_cast<int>(value);
}

int ScalarConvertor::toInt(const char value) {
	return static_cast<int>(value);
}

template <typename T>
float ScalarConvertor::toFloat(const T& value) {
	return static_cast<float>(value);
}

template <typename T>
float ScalarConvertor::toDouble(const T& value) {
	return static_cast<double>(value);
}

t_stringType ScalarConvertor::getType(const std::string& str) {
	if (isChar(str)) {
		return CHAR;
	}
	if (isInt(str)) {
		return INT;
	}
	if (isFloat(str)) {
		return FLOAT;
	}
	if (isDouble(str)) {
		return DOUBLE;
	}
	return OTHERS;
}

bool ScalarConvertor::isChar(const std::string& str) {
	return (str.length() == 1 && (str[0] < '0' || str[0] > '9'));
}

bool ScalarConvertor::isInt(const std::string& str) {
	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-') {
		return false;
	}
	if ((str[0] == '+' || str[0] == '-') && str.length() == 1) {
		return false;
	}
	for (size_t idx = 1; idx < str.length(); idx++) {
		if (!isdigit(str[idx])) {
			return false;
		}
	}
	return true;
}

bool ScalarConvertor::isFloat(const std::string& str) {
	bool	docFlag = false;

	if (str.compare("-inff") == 0 
		|| str.compare("+inff") == 0 
		|| str.compare("nanf") == 0) {
		return true;
	}

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-') {
		return false;
	}
	if ((str[0] == '+' || str[0] == '-') && str.length() == 1) {
		return false;
	}
	for (size_t idx = 1; idx < str.length(); idx++) {
		if (!isdigit(str[idx])) {
			if (idx == str.length() - 1) {
				return (str[idx] == 'f');
			}
			if (str[idx] == '.') {
				if (docFlag) {
					return false;
				}
				docFlag = true;
			} else {
				return false;
			}
		}
	}
	return false;
}

bool ScalarConvertor::isDouble(const std::string& str) {
	bool	docFlag = false;

	if (str.compare("-inf") == 0 
		|| str.compare("+inf") == 0 
		|| str.compare("nan") == 0) {
		return true;
	}

	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-') {
		return false;
	}
	if ((str[0] == '+' || str[0] == '-') && str.length() == 1) {
		return false;
	}
	for (size_t idx = 1; idx < str.length(); idx++) {
		if (!isdigit(str[idx])) {
			if (str[idx] == '.') {
				if (docFlag) {
					return false;
				}
				docFlag = true;
			} else {
				return false;
			}
		}
	}
	return true;
}
