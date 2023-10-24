/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:05:02 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:33:06 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ICharacter.hpp"

#define INVENTORY_SIZE 4

class Character : public ICharacter
{
private:
	std::string name;
	AMateria *inventory[INVENTORY_SIZE];
	
	Character();

public:
	Character(const std::string& name);
	Character(const Character& ref);
	~Character();

	Character& operator=(const Character& ref);

	std::string const	&getName() const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
