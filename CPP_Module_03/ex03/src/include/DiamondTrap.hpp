/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:58:24 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 18:25:08 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;

protected:
	DiamondTrap();
	
public:
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &ref);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& ref);

	std::string	getName() const;
	void		setName(std::string name);
	void		toString() const;
	
	void attack(const std::string& target);
	void whoAmI();
};
