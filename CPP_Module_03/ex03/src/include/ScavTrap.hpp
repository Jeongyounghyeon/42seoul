/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:38:43 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/20 00:27:24 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	ScavTrap();

public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &ref);
	virtual ~ScavTrap();

	virtual ScavTrap& operator=(const ScavTrap& ref);

	virtual void attack(const std::string& target);
	void guardGate();
};
