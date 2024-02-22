/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:10:46 by youjeong          #+#    #+#             */
/*   Updated: 2024/02/22 18:10:47 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define DATA_SEP ","
#define INPUT_SEP "|"
#define STR_INT64_MAX "2147483647"

#include <fstream>
#include <vector>
#include <map>
#include <string>

#define MONTH_ENGLISH(month) ( \
    (month == 1) ? "January" : \
    (month == 2) ? "February" : \
    (month == 3) ? "March" : \
    (month == 4) ? "April" : \
    (month == 5) ? "May" : \
    (month == 6) ? "June" : \
    (month == 7) ? "July" : \
    (month == 8) ? "August" : \
    (month == 9) ? "September" : \
    (month == 10) ? "October" : \
    (month == 11) ? "November" : \
    (month == 12) ? "December" : \
    "Invalid Month")

class BitcoinExchange {
	private:
		BitcoinExchange();
		virtual ~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange& operator=(const BitcoinExchange& ref);

		static std::map<std::string, std::string> parseData(std::ifstream& ifs);
		static std::vector<std::string> getInputContents(std::ifstream& ifs);
		static void changeResultAndOut(
				std::map<std::string, std::string>& data,
				std::vector<std::string>& input);
		static std::vector<std::string> parseInputOneLine(const std::string& line);
		static void exchangeOneLine(
				std::map<std::string, std::string>& data,
				std::vector<std::string> inputOneLine);
		static void validDataFirstLine(const std::string& line);
		static void validInputFirstLine(const std::string& line);
		static void validDateVector(const std::vector<std::string> date);
		static void validRate(const std::string& rate);
		static void validValue(const std::string& value);
		static void validDate(const int year, const int month, const int day);
		static std::vector<std::string> split(const std::string& str, const std::string& sep);
		
	public:
		
		static void exchange(std::ifstream& data, std::ifstream& input);
};
