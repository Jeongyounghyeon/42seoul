/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:17:41 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/10 15:08:16 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "term_color.h"

#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook(void) : idx(0),
							cnt_contact(0) {
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::service(void) {
	std::string	cmd;
	
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|    Welcome to crappy awesome phonebook    |" << std::endl;
	std::cout << "| Please enter either ADD, SEARCH, or EXIT  |" << std::endl;
	std::cout << " ⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺ " << std::endl;
	
	cmd = "";
	while (cmd != "EXIT") {
		std::cout << "enter the command you want: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			this->add();
		else if (cmd == "SEARCH")
			this->search();
	}
}

void	PhoneBook::add(void) {
	Contact		&contact = this->contacts[this->idx++ % 8];
	std::string	str;
	
	str = "";
	while (str == "") {
		std::cout << "Enter your first name: ";
		std::getline(std::cin, str);
		contact.setFirstName(str);
	}
	
	str = "";
	while (str == "") {
		std::cout << "Enter your last name: ";
		std::getline(std::cin, str);
		contact.setLastName(str);
	}
	
	str = "";
	while (str == "") {
		std::cout << "Enter your nickname: ";
		std::getline(std::cin, str);
		contact.setNickname(str);
	}
	
	str = "";
	while (str == "") {
		std::cout << "Enter your phone number: ";
		std::getline(std::cin, str);
		contact.setPhoneNumber(str);
	}
	
	str = "";
	while (str == "") {
		std::cout << "Enter your darkest secret: ";
		std::getline(std::cin, str);
		contact.setDarkestSecret(str);
	}

	if (this->cnt_contact < CNT_CONTACT_MAX)
		this->cnt_contact++;
	std::cout << "Your contact has been saved successfully!" << std::endl;
}

void	PhoneBook::search(void) const {
	std::string str_num;
	
	this->toString();
	if (this->cnt_contact == 0) {
		std::cout << "Please add at least one contact." << std::endl;
		return ;
	}
	do {
		std::cout << "Enter the index you want to search (0 ~ " << this->cnt_contact - 1 << "): ";
		if (std::getline(std::cin, str_num) && (str_num != "")
			&& (str_num.length() == 1 && str_num[0] >= '0' && str_num[0] - '0' < this->cnt_contact)) {
				this->contacts[str_num[0] - '0'].toString();
		}
		else if (str_num != "")
			std::cout << TC_YELLOW
						<< "Please enter index between 0 and " << this->cnt_contact - 1 << std::endl
						<< TC_WHITE;
	} while (!(str_num.length() == 1 && str_num[0] >= '0' && str_num[0] - '0' < this->cnt_contact));
}

void	PhoneBook::toString(void) const {
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++) {
		Contact		contact = this->contacts[i];
		if (i < this->cnt_contact) {
			std::string	str;

			std::cout << "|" << std::setw(10) << i << "|";
			
			str = formatTextForColumn(contact.getFirstName().substr(0, 11));
			std::cout << std::setw(10) << str << "|";

			str = formatTextForColumn(contact.getLastName().substr(0, 11));
			std::cout << std::setw(10) << str << "|";
			
			str = formatTextForColumn(contact.getNickname().substr(0, 11));
			std::cout << std::setw(10) << str << "|";
			
			std::cout << std::endl;
		}
	}
	std::cout << " ⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺ " << std::endl;
}

std::string	PhoneBook::formatTextForColumn(std::string str) const {
	std::string	formatStr;

	formatStr = str.substr(0, 11);
	if (formatStr.length() > 10) {
		formatStr[9] = '.';
		formatStr[10] = 0;
	}
	return (formatStr);
}