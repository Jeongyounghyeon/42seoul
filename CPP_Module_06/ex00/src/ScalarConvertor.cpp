/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:57:34 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/01 21:27:57 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "ScalarConvertor.hpp"

char ScalarConvertor::stringToChar(const char* const str) {
	int valueOfIntType;
	char value;

	valueOfIntType = stringToInt(str);
	if (valueOfIntType < 32 || valueOfIntType > 126)
		throw std::string("Non displayable");
	value = static_cast<char>(valueOfIntType);

	return value;
}

int ScalarConvertor::stringToInt(const char* const str) {
	double valueOfDoubleType;
	int value;

	valueOfDoubleType = stringToDouble(str);
	if (std::isnan(valueOfDoubleType) || std::isinf(valueOfDoubleType))
		throw std::string("impossible");
	value = static_cast<int>(valueOfDoubleType);

	return value;
}

float ScalarConvertor::stringToFloat(const char* const str) {
	char *pend;
	float value;

	value = std::strtof(str, &pend);
	if (*pend != 0 && *pend != 'f' && *pend != 0)
		throw std::string("impossible");

	return value;
}

double ScalarConvertor::stringToDouble(const char* str) {
	char *pend;
	double value;

	value = std::strtod(str, &pend);
	if (*pend != 0 && *pend != 'f' && *pend != 0)
		throw std::string("impossible");
	
	return value;
}

void ScalarConvertor::convert(const char *str) {
	try {
		char valueOfChar = ScalarConvertor::stringToChar(str);

		std::cout << "char: \'" << valueOfChar << "\'" << std::endl;
	} catch (std::string& str) {
		std::cout << "char: " << str << std::endl;
	}

	try {
		int valueOfInt = ScalarConvertor::stringToInt(str);

		std::cout << "int: " << valueOfInt << std::endl;
	} catch (std::string& str) {
		std::cout << "int: " << str << std::endl;
	}

	try {
		float valueOfFloat = stringToFloat(str);

		// 소수점 유무 처리
		if (valueOfFloat == static_cast<int>(valueOfFloat)) {
			std::cout << "float: " << valueOfFloat << ".0f" << std::endl;
		} else {
			std::cout << "float: " << valueOfFloat << "f" << std::endl;
		}
	} catch (std::string& str) {
		std::cout << "float: " << str << std::endl;
	}

	try {
		double valueOfDouble = stringToDouble(str);

		// 소수점 유무 처리
		if (valueOfDouble == static_cast<int>(valueOfDouble)) {
			std::cout << "double: " << valueOfDouble << ".0" << std::endl;
		} else {
			std::cout << "double: " << valueOfDouble << std::endl;
		}
	} catch (std::string& str) {
		std::cout << "double: " << str << std::endl;
	}
}
