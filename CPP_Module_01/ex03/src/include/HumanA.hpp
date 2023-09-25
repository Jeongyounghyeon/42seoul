/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 23:52:05 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/25 23:17:24 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

# include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon		&weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	
	std::string	getName(void) const;
	Weapon&		getWeapon(void) const;
	void		setName(std::string name);

	void	attack() const;
};
