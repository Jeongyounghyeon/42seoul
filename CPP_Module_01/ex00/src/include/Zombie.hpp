/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:22:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/12 13:00:54 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie
{
private:
	std::string	name;

public:
	Zombie(std::string name);
	~Zombie(void);
	
	std::string	getName(void) const;
	void		setName(std::string name);
	
	void announce(void) const;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);