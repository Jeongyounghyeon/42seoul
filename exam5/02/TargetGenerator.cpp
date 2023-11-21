/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:56:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 19:03:39 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
}

TargetGenerator::~TargetGenerator() {
}

void TargetGenerator::learnTargetType(ATarget* target) {
	if (target) {
		this->targets[target->getType()] = target;
	}
}

void TargetGenerator::forgetType(std::string const &target) {
	if (this->targets.find(target) != this->targets.end()) {
		targets.erase(target);
	}
}

ATarget* TargetGenerator::createTarget(std::string const &target) {
	if (this->targets.find(target) != targets.end()) {
		return this->targets[target];
	}

	return 0;
}