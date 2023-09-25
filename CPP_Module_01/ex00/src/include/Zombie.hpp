/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:22:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/25 23:16:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class Zombie
{
private:
	std::string	name;

public:
	Zombie(std::string name);
	~Zombie(void);
	
	void	announce(void) const;
	
	std::string	getName(void) const;
	void		setName(std::string name);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
