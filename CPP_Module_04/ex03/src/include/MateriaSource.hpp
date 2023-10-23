/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:26:02 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/22 20:18:02 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

#define MATERIAS_SIZE 4

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materias[MATERIAS_SIZE];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& ref);
	~MateriaSource();

	MateriaSource operator=(const MateriaSource &ref);
	
	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const & type);
};
