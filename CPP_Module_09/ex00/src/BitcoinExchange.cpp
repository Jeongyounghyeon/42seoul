/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:10:48 by youjeong          #+#    #+#             */
/*   Updated: 2024/02/22 18:10:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

#include "BitcoinExchange.hpp"

void BitcoinExchange::exchange(std::ifstream& dataIfs, std::ifstream& inputIfs) {
	std::map<std::string, std::string> data;
	std::vector<std::string> inputContents;

	data = parseData(dataIfs);
	inputContents = getInputContents(inputIfs);
	changeResultAndOut(data, inputContents);
}

std::map<std::string, std::string> BitcoinExchange::parseData(std::ifstream& ifs) {
	std::map<std::string, std::string> data;

	std::string line;

	if (!std::getline(ifs, line)) { throw std::runtime_error("data file is Empty."); }

	validDataFirstLine(line);

	while (std::getline(ifs, line)) {
		std::vector<std::string> date_rate = split(line, DATA_SEP);

		if (date_rate.size() != 2) {
			std::stringstream errorMessageStream;

			errorMessageStream << "line in data file is not valid format(date,exchange_rate).\n"
								<< "\t" << line; 

			throw std::runtime_error(errorMessageStream.str());
		}

		std::vector<std::string> date = split(date_rate.at(0), "-");
		validDateVector(date);
		validRate(date_rate.at(1));

		data[date_rate.at(0)] = date_rate.at(1);
	}

	return data;
}

std::vector<std::string> BitcoinExchange::getInputContents(std::ifstream& ifs) {
	std::vector<std::string> inputContents;

	std::string line;

	if (!std::getline(ifs, line)) { throw std::runtime_error("Input file is Empty."); }

	validInputFirstLine(line);

	while (std::getline(ifs, line))
		inputContents.push_back(line);

	return inputContents;
}

void BitcoinExchange::changeResultAndOut(
		std::map<std::string, std::string>& data,
		std::vector<std::string>& input) {

	(void)data;

	while (!input.empty()) {
		try {
			std::vector<std::string> inputOneLine = parseInputOneLine(input.at(0));
			exchangeOneLine(data, inputOneLine);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		input.erase(input.begin());
	}
}

std::vector<std::string> BitcoinExchange::parseInputOneLine(const std::string& line) {	std::vector<std::string> year_month_day_value;
	std::vector<std::string> date_value;

	date_value = split(line, " | ");

	if (date_value.size() != 2) {
		std::stringstream errorMessageStream;
		errorMessageStream << "Bad input => " << line;
		throw std::runtime_error(errorMessageStream.str());
	}

	std::vector<std::string> date = split(date_value.at(0), "-");\
	validDateVector(date);
	validValue(date_value.at(1));

	return date_value;
}

void BitcoinExchange::exchangeOneLine(
	std::map<std::string, std::string>& data,
	std::vector<std::string> inputOneLine) {
	char *tmp;

	std::map<std::string, std::string>::iterator iter;
	iter = data.find(inputOneLine.at(0));
	if (iter == data.end()) {
		iter = data.lower_bound(inputOneLine.at(0));
		if (iter == data.begin()) {
			std::stringstream errorMessageStream;
			errorMessageStream << "Bad input => " << inputOneLine.at(0);
			throw std::runtime_error(errorMessageStream.str());
		}
		iter-- = data.upper_bound(inputOneLine.at(0));
	}

	double rate = strtod(iter->second.c_str(), &tmp);
	double value = strtod(inputOneLine.at(1).c_str(), &tmp) * rate;
	std::cout << inputOneLine.at(0) << " => " << inputOneLine.at(1) << " = " << value << std::endl;
}

void BitcoinExchange::validDataFirstLine(const std::string& line) {
	if (line.compare("date,exchange_rate") != 0)
		throw std::runtime_error("An exception occurred in the first line of data file");
}

void BitcoinExchange::validInputFirstLine(const std::string& line) {
	if (line.compare("date | value") != 0)
		throw std::runtime_error("An exception occurred in the first line of input file");
}

void BitcoinExchange::validDateVector(const std::vector<std::string> date) {
	if (date.size() != 3)
		throw std::runtime_error("date must following format (YYYY-MM-DD).");

	std::string year = date.at(0);
	std::string month = date.at(1);
	std::string day = date.at(2);

	/* year validation */
	if (year.length() != 4)
		throw std::runtime_error("date must following format (YYYY-MM-DD).");

	for (size_t idx = 0; idx < year.length(); idx++) {
		if (!(year[idx] >= '0' && year[idx] <= '9'))
			throw std::runtime_error("The year should be Number.");
	}

	/* month validation */
	if (month.length() != 2)
		throw std::runtime_error("date must following format (YYYY-MM-DD).");

	for (size_t idx = 0; idx < month.length(); idx++) {
		if (!(month[idx] >= '0' && month[idx] <= '9'))
			throw std::runtime_error("The month should be Number.");
	}

	/* day validation */
	if (day.length() != 2)
		throw std::runtime_error("date must following format (YYYY-MM-DD).");

	for (size_t idx = 0; idx < day.length(); idx++) {
		if (!(day[idx] >= '0' && day[idx] <= '9'))
			throw std::runtime_error("The day should be Number.");
	}

	validDate(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str()));
}

void BitcoinExchange::validRate(const std::string& rate) {
	char* restOfNumber = 0;
	double rateOfDouble;
	
	rateOfDouble = strtod(rate.c_str(), &restOfNumber);
	if (std::string(restOfNumber).length() > 0
		|| rateOfDouble < 0
	) {
		throw std::runtime_error("not a positive rate in data file.");
	}

	if (rateOfDouble > 2147483647)
		throw std::runtime_error("too large a rate in data file.");
}

void BitcoinExchange::validValue(const std::string& value) {
	char* restOfNumber = 0;
	double valueOfDouble;
	
	valueOfDouble = strtod(value.c_str(), &restOfNumber);
	if (std::string(restOfNumber).length() > 0
		|| valueOfDouble < 0
	) {
		throw std::runtime_error("not a positive number.");
	}

	if (valueOfDouble > 1000)
		throw std::runtime_error("too large a number.");
}

void BitcoinExchange::validDate(const int year, const int month, const int day) {
	time_t timerNow = time(NULL);
	struct tm* timeNow = localtime(&timerNow);

	if (!(month >= 1 && month <= 12))
		throw std::runtime_error("The month should be 1 ~ 12.");

	if (month == 2) {
		if (year % 4 == 0 && year % 400 != 0) {
			if (day > 29)
				throw std::runtime_error("February of a leap year cannot exceed 29 days.");
		} else {
			if (day > 28)
				throw std::runtime_error("February of a normal year cannot exceed 28 days.");
		}
	} else if (month == 4 || month == 6 || month == 9 || month ==11) {
		if (day > 30) {
			std::stringstream errorMessageStream;
			errorMessageStream << MONTH_ENGLISH(month) << " can't be more than 30 days.";
			throw std::runtime_error(errorMessageStream.str());
		}
	} else {
		if (day > 31) {
			std::stringstream errorMessageStream;
			errorMessageStream << MONTH_ENGLISH(month) << " can't be more than 31 days.";
			throw std::runtime_error(errorMessageStream.str());
		}
	}

	if (year > timeNow->tm_year + 1900
		|| (year == timeNow->tm_year + 1900 && month > timeNow->tm_mon + 1)
		|| (year == timeNow->tm_year + 1900 && month == timeNow->tm_mon + 1 && day > timeNow->tm_mday)
	) {
		throw std::runtime_error("The date must be earlier than the present.");
	}
}

std::vector<std::string> BitcoinExchange::split(const std::string& str, const std::string& sep) {
	std::vector<std::string> res;

	size_t idxStart = 0;
	for (size_t idx = 0; idx < str.length(); idx++) {
		if (str.substr(idx, sep.length()).compare(sep) == 0) {
			res.push_back(str.substr(idxStart, idx - idxStart));
			idxStart = idx + sep.length();
			idx += sep.length() - 1;
		}
	}

	if (idxStart != str.length())
		res.push_back(str.substr(idxStart, str.length() - idxStart));

	return res;
}