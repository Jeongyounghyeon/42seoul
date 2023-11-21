/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:34:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/21 17:34:39 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {
}

BrickWall::BrickWall(const BrickWall &ref) : ATarget(ref) {
	*this = ref;
}

BrickWall::~BrickWall() {
}

BrickWall& BrickWall::operator=(const BrickWall &ref) {
	if (this == &ref)
		return *this;
	
	ATarget::operator=(ref);

	return *this;
}

BrickWall* BrickWall::clone() const {
	return new BrickWall();
}