/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:24:58 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/25 22:01:59 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal
{
private:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& ref);
	virtual ~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal &ref);

	std::string	getType() const;
	void		setType(std::string type);
	
	void makeSound() const;
};
