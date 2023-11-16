/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:54:39 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/01 21:10:28 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConvertor {
	private:
		ScalarConvertor();
		ScalarConvertor(const ScalarConvertor& ref);
		~ScalarConvertor();

		ScalarConvertor& operator=(const ScalarConvertor& ref);

		static char stringToChar(const char* str);
		static int stringToInt(const char* str);
		static float stringToFloat(const char* str);
		static double stringToDouble(const char* str);
	
	public:
		static void convert(const char *str);
};