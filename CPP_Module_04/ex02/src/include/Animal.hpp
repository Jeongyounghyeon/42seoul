/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:00:21 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/25 22:02:11 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal
{
private:
	std::string type;

public:
	Animal();
	Animal(const Animal& ref);
	virtual ~Animal();

	Animal& operator=(const Animal &ref);

	std::string	getType() const;
	void		setType(std::string type);
	
	virtual void makeSound() const = 0;
};
