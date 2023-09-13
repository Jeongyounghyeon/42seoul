/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:22:04 by youjeong          #+#    #+#             */
/*   Updated: 2023/09/12 18:51:43 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
	std::string	name;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	
	void	announce(void) const;
	
	std::string	getName(void) const;
	void		setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif