/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 22:53:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:39:39 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() {
	for (int idx = 0; idx < MATERIAS_SIZE; idx++) {
		this->materias[idx] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ref) {
	*this = MateriaSource();
	*this = ref;
}

MateriaSource::~MateriaSource() {
	for (int idx = 0; idx < MATERIAS_SIZE; idx++) {
		if (this->materias[idx]) {
			delete this->materias[idx];
		}
	}
}

MateriaSource MateriaSource::operator=(const MateriaSource &ref) {
	if (this == &ref) {
		return *this;
	}
	
	for (int idx = 0; idx < MATERIAS_SIZE; idx++) {
		if (this->materias[idx]) {
			delete this->materias[idx];
		}
		if (ref.materias[idx]) {
			this->materias[idx] = ref.materias[idx]->clone();
		} else {
			this->materias[idx] = 0;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia) {
	int idx;
	
	for (idx = 0; idx < MATERIAS_SIZE; idx++) {
		if (this->materias[idx] == 0) {
			this->materias[idx] = materia;
			break;
		}
	}
	if (idx == MATERIAS_SIZE) {
		std::cout << "Materia Source's space is full" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	AMateria* materia = 0;
	
	for (int idx = 0; idx < MATERIAS_SIZE && this->materias[idx]; idx++) {
		if (type == this->materias[idx]->getType()) {
			return this->materias[idx]->clone();
		}
	}
	
	return materia;
}