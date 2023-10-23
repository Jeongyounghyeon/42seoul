/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:01:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/18 13:53:48 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
	
public:
	Dog();
	Dog(const Dog& ref);
	~Dog();

	Dog& operator=(const Dog &ref);

	Brain*	getBrain() const;
	void	setBrain(Brain *brain);
	
	void makeSound() const;
};
