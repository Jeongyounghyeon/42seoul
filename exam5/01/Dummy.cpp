/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:55:18 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:56:36 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {
}

Dummy::Dummy(const Dummy &ref) : ATarget(ref) {
	*this = ref;
}

Dummy::~Dummy() {
}

Dummy& Dummy::operator=(const Dummy &ref) {
	if (this == &ref)
		return *this;
	
	ATarget::operator=(ref);

	return *this;
}

Dummy* Dummy::clone() const {
	return new Dummy();
}