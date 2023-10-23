/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:36:28 by youjeong          #+#    #+#             */
/*   Updated: 2023/10/18 14:48:30 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define LENGHT_IDEAS 100

class Brain
{
private:
	std::string ideas[LENGHT_IDEAS];

public:
	Brain();
	Brain(const Brain& ref);
	~Brain();

	Brain& operator=(const Brain& ref);

	std::string	getIdeas(int idx) const;
	void		setIdeas(std::string ideas, int idx);
};
