/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:42:26 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/24 19:35:51 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain's defualt constructor called." << std::endl;
	
	for (int i = 0; i < LENGHT_IDEAS; i++) {
		ideas[i] = "";
	}
}

Brain::Brain(const Brain& ref) {
	std::cout << "Brain's copy constructor called." << std::endl;

	*this = ref;
}

Brain::~Brain() {
	std::cout << "Brain's destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& ref) {
	if (this == &ref)
		return *this;
	
	for (int i = 0; i < LENGHT_IDEAS; i++)
		setIdeas(ref.getIdeas(i), i);
	
	return *this;
}

std::string Brain::getIdeas(int idx) const {
	return this->ideas[idx];
}

void Brain::setIdeas(std::string ideas, int idx) {
	this->ideas[idx] = ideas;
}
