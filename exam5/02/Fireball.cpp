/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:29:44 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/20 18:53:49 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {
}

Fireball::Fireball(const Fireball &ref) : ASpell(ref) {
	*this = ref;
}

Fireball::~Fireball() {
}

Fireball& Fireball::operator=(const Fireball &ref) {
	if (this == &ref)
		return *this;
	
	ASpell::operator=(ref);

	return *this;
}

Fireball* Fireball::clone() const {
	return new Fireball();
}