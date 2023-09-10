/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:17:26 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/10 15:05:32 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

std::string Contact::getFirstName(void) const {
	return (this->firstName);
}

std::string Contact::getLastName(void) const {
	return (this->lastName);
}

std::string Contact::getNickname(void) const {
	return (this->nickname);
}

std::string Contact::getPhoneNumber(void) const {
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {
	return (this->darkestSecret);
}

void		Contact::setFirstName(std::string str) {
	this->firstName = str;
}

void		Contact::setLastName(std::string str) {
	this->lastName = str;
}

void		Contact::setNickname(std::string str) {
	this->nickname = str;
}

void		Contact::setPhoneNumber(std::string str) {
	this->phoneNumber = str;
}

void		Contact::setDarkestSecret(std::string str) {
	this->darkestSecret = str;
}

void		Contact::toString(void) const {
	std::cout << "Information of " << this->getFirstName() << ' ' << this->getLastName() << std::endl;
	std::cout << "First Name:     " << this->getFirstName() << std::endl;
	std::cout << "Last Name:      " << this->getLastName() << std::endl;
	std::cout << "Nickname:       " << this->getNickname() << std::endl;
	std::cout << "Phone number:   " << this->getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->getDarkestSecret() << std::endl;
}