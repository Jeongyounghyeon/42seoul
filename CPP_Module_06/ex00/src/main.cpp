/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:17:31 by youjeong          #+#    #+#             */
/*   Updated: 2023/11/01 21:20:27 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>

#include "ScalarConvertor.hpp"

bool validArgument(int argc, char **argv);

int main(int argc, char **argv) {
	std::cout << "I have to rename execute file name" << std::endl;

	if (!validArgument(argc, argv))
		return 1;

	ScalarConvertor::convert(argv[1]);

	return 0;
}

bool validArgument(int argc, char **argv) {
	if (argc != 2			// argument count check
		|| !argv[1][0]) {	// empty argument chcek
		std::cout << "Please check execute argument!" << std::endl;
		
		return false;
	}

	return true;
}