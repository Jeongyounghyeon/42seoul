/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:18:40 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/22 19:49:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>

#include "Harl.hpp"

Harl::Harl(void) {
	this->complains["DEBUG"] = &Harl::debug;
	this->complains["INFO"] = &Harl::info;
	this->complains["WARNING"] = &Harl::warning;
	this->complains["ERROR"] = &Harl::error;
};

Harl::~Harl(void) {};

void	Harl::complain(std::string level) const {
	if (complains.find(level) != complains.end())
		(this->*(complains.at(level)))();
	else
		std::cout << "Harl::complain: " << level << " is invalid complaint level" << std::endl;
}

void	Harl::debug(void) const {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) const {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) const {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) const {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
