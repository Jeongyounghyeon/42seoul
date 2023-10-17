/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:38:43 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/17 18:40:23 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	FragTrap();

public:
	FragTrap(const std::string name);
	FragTrap(const FragTrap &ref);
	~FragTrap();

	virtual FragTrap& operator=(const FragTrap& ref);

	virtual void attack(const std::string& target);
	void highFivesGuys(void);
};
