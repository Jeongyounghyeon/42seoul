/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:54:39 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 16:50:47 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

typedef enum e_stringType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    OTHERS
} t_stringType;

class ScalarConvertor {
	private:
		ScalarConvertor();
		ScalarConvertor(const ScalarConvertor& ref);
		~ScalarConvertor();

		ScalarConvertor& operator=(const ScalarConvertor& ref);

		template <typename T>
		static void convert(const T& value);
		// static void convert(const char value);
		
		static void convertImpossible();
		static t_stringType getType(const std::string& str);

		template <typename T>
		static char toChar(const T& value);
		static char toChar(const int& value);

		template <typename T>
		static int toInt(const T& value);
		static int toInt(const char value);

		template <typename T>
		static float toFloat(const T& value);

		template <typename T>
		static float toDouble(const T& value);

		static bool isChar(const std::string& str);
		static bool isInt(const std::string& str);
		static bool isFloat(const std::string& str);
		static bool isDouble(const std::string& str);

	public:
		static void convert(const std::string& str);
};
