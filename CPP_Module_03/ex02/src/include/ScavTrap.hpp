/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:38:43 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 19:23:37 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();

public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &ref);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& ref);

	void attack(const std::string& target);
	void guardGate();
};
