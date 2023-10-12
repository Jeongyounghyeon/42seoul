/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:51:56 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/12 17:46:09 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {}
Weapon::~Weapon(void) {}

const std::string& Weapon::getType(void) const {
	return this->type;
}

void	Weapon::setType(std::string type) {
	this->type = type;
}