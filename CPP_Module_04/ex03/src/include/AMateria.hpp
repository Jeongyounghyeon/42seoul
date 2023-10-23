/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:09:36 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/22 01:02:05 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string type;

	AMateria();
	
public:
	AMateria(std::string const &type);
	AMateria(const AMateria &ref);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& ref);

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
